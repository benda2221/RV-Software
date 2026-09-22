# 14 个 legacy 运行失败用例分析

本文记录 2026-08-11 使用当前 Dandelion LLVM 21.1.8、Zircon RTL 和 ZirconSim 对 14 个“可生成镜像但 legacy 自检失败”的用例进行的复测。目标侧使用 `USE_SIMULATOR_ONLY_MODE=0`，同时比较 GPR 和 FPR 写回；host 对照使用相同 NMSIS 源、相同 `nmsis_core.h` 固定 cycle seed、GCC `-O2 -ffp-contract=off` 和系统 libm。

## 汇总

- 14/14 均完成重新编译和运行。
- 修复参考模拟器的两个假阳性后，2026-08-11 当时记录为：1 个 difftest 首错，13 个运行到 `main` 返回非零。
- host 对照为：12 个通过，2 个仅 q15 子项失败。
- 这些结果不能归结为“14 个 NMSIS 算法都算错”。主要阻塞是 RV32D 编译选项与处理器实际只实现 RV32F 的不一致、legacy SNR/随机数 helper 隐式使用 double、目标运行时 64 位除法的 endian 错误，以及一个在双 LSU 同包读取处暴露的模拟器内存模型问题。

2026-08-12 后续验证已经完成 RV32F 收窄，并纠正了 BasicMath 首错的归因：该错误不是处理器双 LSU 通路，而是 ZirconSim DUT 内存模型错误处理非对齐 `sw`，提前破坏了随后由 LSU1 读取的数据。修复非对齐 load/store 后，原始 BasicMath legacy case 在 GPR/FPR difftest 下完整通过。

| # | legacy case | 目标侧最终结果 | host 对照 | 当前首要原因 |
|---:|---|---|---|---|
| 1 | `BasicMathFunctions/riscv_basic_math_functions` | 初始 difftest：`lbu a2,0(a6)`，DUT `0`、ref `0xdd`；修复后 PASS | PASS | ZirconSim DUT 内存模型对非对齐 `sw` 的掩码/跨 word 处理错误；不是处理器双 LSU 错误 |
| 2 | `DistanceFunctions/riscv_distance` | `riscv_minkowski_distance_f32` mismatch | PASS | `generate_rand_f32` 的 double 表达式被编成 RV32D；D 指令未实现，输入退化为 0 |
| 3 | `FilteringFunction/LMSPart/riscv_fir` | f32/q31/q15 SNR failure | q15 failure，`-8.623777 dB` | target 的 SNR helper 经 double `log10` 使用未实现 RV32D；此外 q15 在 host 也复现，是上游满幅随机输入下的真实 q15 数值/溢出问题 |
| 4 | `FilteringFunction/NLMSPart/riscv_fir` | f32/q31/q15 SNR failure | q15 failure，`-12.107554 dB` | 同上：target SNR helper/RV32D 阻塞；q15 另有可在 host 复现的上游数值/溢出问题 |
| 5 | `FilteringFunction/firDecimatorPart/riscv_fir` | f32/q31/q15/fast-q31/fast-q15 SNR failure | PASS | SNR helper 的 double `log10` 路径使用未实现 RV32D，不能据此判定 FIR 输出错误 |
| 6 | `FilteringFunction/firInterpolatePart/riscv_fir` | f32/q31/q15 SNR failure | PASS | 同上 |
| 7 | `FilteringFunction/firLatticePart/riscv_fir` | f32/q31/q15 SNR failure | PASS | 同上 |
| 8 | `FilteringFunction/firSparsePart/riscv_fir` | f32/q31/q15/q7 SNR failure | PASS | 同上 |
| 9 | `FilteringFunction/iirLatticePart/riscv_fir` | f32/q31/q15 SNR failure | PASS | 同上 |
| 10 | `FilteringFunction/iirdf1/riscv_fir` | f32/q31/q15/fast/32x64 SNR failure | PASS | SNR helper/RV32D；中途出现的 `fcvt.w.s` difftest 是参考模拟器正溢出处理错误，修复后不再出现 |
| 11 | `FilteringFunction/iirdf2t/riscv_fir` | f32/stereo-f32 SNR failure | PASS | SNR helper的 double `log10` 路径使用未实现 RV32D |
| 12 | `QuaternionMathFunctions/riscv_quaternion` | `riscv_rotation2quaternion_f32` index 3 mismatch | PASS | `generate_rand_f32` 输入因未实现 RV32D 退化为 0，零矩阵边界路径使实现与 reference 分歧 |
| 13 | `StatisticsFunctions/riscv_statistics` | var_q31、std_q15、var_q15、entropy_f64、KL-f64 failure | PASS | q31/q15 variance/std 被错误的 target `__divdi3` 破坏；f64 子项使用未实现 RV32D |
| 14 | `TransformFunction/cfft/riscv_tranform` | cfft f32/q31/q15、radix2/radix4 全部 SNR failure | PASS | 所有判定共用含 double `log10` 的 SNR helper；host 全部通过，当前结果不能归类为 CFFT 运算单元错误 |

## 根因证据

### 1. 原配置启用 D，但处理器和参考模拟器没有 RV32D 执行路径

2026-08-11 复测时 base port 使用 `-march=rv32imfd`，LLC 使用 `-mattr=+m,+f,+d`。实际汇编包含 `fld/fsd`、`fcvt.d.w`、`fdiv.d`、`fmul.d` 和 `fcvt.s.d`。例如当时的 `generate_rand_f32` 被编译为：

```text
fcvt.d.w fa5, a0
fdiv.d   fa5, fa5, fs0
fcvt.s.d fa5, fa5
```

但是 `Frontend/Decode/Decoder.scala` 的 FPU/Mem/FDiv decode map 只列出 `.S`、`FLW/FSW`、`FDIV.S/FSQRT.S`。`RVISA.scala` 虽声明了 RV32D BitPat，它们没有加入 decode map。ZirconSim 同样只有 32-bit `float fpr[32]` 和 `.S` 执行分支。D 指令没有触发 illegal instruction，而是被双方静默跳过，所以 difftest 仍可能一致，但程序数据已经错误。

两个 legacy helper 会把本来是 f32 的测试也带入 D 路径：

```c
src[i] = (float32_t)((...) * 1.0 / Q31_MAX);
SNR = 10 * log10(EnergySignal / EnergyError);
```

第一处的 `1.0` 是 double；第二处的 `log10` 返回 double。因此 Distance/Quaternion 的 f32 输入会退化，Filtering/CFFT 的 SNR 判定也会失真。

当前实现已选择 RV32F 路径：Clang/assembler 使用 `-march=rv32imf`，LLC 使用 `-mattr=+m,+f,-d`；f32 随机数使用 `1.0f` 和显式 `float32_t` 除数，SNR 使用 `10.0f * log10f(...)`。f64 helper 和 double compatibility wrapper 仅在显式定义 `ZIRCON_ENABLE_FLOAT64` 时编译，manifest 中 37 个 f64 benchmark 条目继续保持 skipped。BasicMath ELF 属性为 `rv32i2p1_m2p0_f2p2`，反汇编中没有 RV32D 指令或 `__*df*` 软件双精度调用。

### 2. BasicMath 首错来自非对齐 store 破坏相邻数组

RV32F 重编后失败包地址移动为：

```text
80019fa0  feq.s zero,ft0,ft0
80019fa4  addi a3,a4,1
80019fa8  addi a5,a5,1
80019fac  nop
80019fb0  nop
80019fb4  lbu a1,0(a5)   # slot 5 / LSU0
80019fb8  lbu a2,0(a6)   # slot 6 / LSU1: DUT=0, ref=0xdd
80019fbc  nop
```

逐周期记录显示 LSU1 地址正确，为 `0x80027a48`，AXIMemory 返回的低字节已经是 0。该位置对应 `q7_b[125]`，初始化时 DUT 和 reference 都曾正确写入 `0xdd`。真正破坏发生在更早的 `riscv_and_u8` 批处理：输出数组 `q7_out_array` 从非对齐地址 `0x80027a4a` 开始，算法对其执行 `sw`。旧 DUT AXIMemory 固定使用未按地址偏移的 `0xF` mask，同时把数据左移 16 位，因而把同一 aligned word 的 byte 0/1（即 `q7_b[125:126]`）清零；reference 的 mask 行为不同，差分最终在后续 `lbu` 才暴露。

现在 DUT 与 reference 内存都按地址逐字节读写，`lw/sw` 可以跨 word，且不会改写访问范围之外的字节。仅修正 store 后原 difftest 已消失，但 u8/u16 逻辑结果仍暴露非对齐 load 不跨 word；补齐 load 后，完整 case 的 51 个子项全部 PASS，最终为 386510 cycles、1438512 committed instructions，无 GPR/FPR mismatch。

### 3. Statistics 定点失败来自 target 64 位除法运行时

`riscv_var_q31`、`ref_var_q31`、`ref_std_q15` 和 `ref_var_q15` 都依赖 RV32 上的软件 64 位除法。`base-port/tool/src/int64.c` 当前定义：

```c
typedef union {
    du_int all;
    struct {
        su_int high;
        su_int low;
    } s;
} udwords;
```

当前 ABI 是 little-endian，低地址字段应对应 low word；现有顺序使 `__udivmoddi4` 把高低 32 位解释反了。目标实测分别得到：var_q31 expected `-1986265088`、actual `677380096`；std_q15 expected `32767`、actual `0`；var_q15 expected `0`、actual `-6`。host 使用正确的本机 64 位除法后全部通过，因此这是 base runtime 问题，不是处理器整数乘除流水线问题。

### 4. LMS/NLMS q15 是可在 host 复现的 legacy 数值问题

两个源文件都注明必须注意 overflow，并对 q15 使用满幅随机数据。相同 seed 的 host 运行中，f32/q31 通过，只有 q15 分别为 `-8.623777 dB` 和 `-12.107554 dB`。这两个 q15 failure 与 Zircon RTL、Simulator 和 Dandelion codegen 无关；后续应限制输入幅度或核对当前 NMSIS 版本的 q15 reference/缩放约定。

## 本轮同时修复的测试基础设施问题

1. generator 以前只按源文件相对路径识别 `#include "...helper.c"`。嵌套 Filtering/Transform legacy 源借助 Makefile include root 找到 helper，scanner 却又把同一 helper 作为独立翻译单元加入，造成 `ref_detrm/ref_cofact` duplicate symbol。现在 scanner 按实际 include roots 解析，14 个目标均可链接。
2. ZirconSim 的 `FDIV.S` 把任何除数为零的结果强制为 0；已改为 IEEE-754 运算，使 `0/0` 为 canonical NaN、非零数除零为 infinity。
3. ZirconSim 的 `FCVT.W.S/WU.S` 直接使用越界 host cast；已按 RISC-V 规则处理 NaN 和正负溢出。`iirdf1` 的 DUT `0x7fffffff` 是正确结果，旧 reference `0x80000000` 是假阳性。
4. ZirconSim 的 DUT/reference 内存访问现在都用连续字节组装，正确支持跨 word 的非对齐 load/store；这修复了 BasicMath 的假双-LSU差分以及随后 u8/u16 logical 结果错误。
5. difftest 失败信息增加最近 8 个周期的两路 LSU op/address/rdata，便于直接区分地址生成、内存返回和写回问题。

## 复现与日志

单个目标侧 difftest：

```bash
make TEST_SYSTEM=legacy SUITE=FilteringFunction \
  TEST_CASE=iirdf1__riscv_fir USE_SIMULATOR_ONLY_MODE=0 \
  ARGS=200000000 run
```

复现并验证本次 BasicMath 修复：

```bash
make TEST_SYSTEM=legacy SUITE=BasicMathFunctions \
  TEST_CASE=riscv_basic_math_functions clean image
USE_SIMULATOR_ONLY_MODE=0 make TEST_SYSTEM=legacy SUITE=BasicMathFunctions \
  TEST_CASE=riscv_basic_math_functions run
```

当前预期结果为 `SIMULATION ENDED SUCCESSFULLY` 和 `all test are passed`。

本轮目标侧日志位于 `reports/legacy_14_difftest_20260811/`，host 对照位于 `reports/legacy_14_host_20260811/`。关键汇总文件为：

- `summary.tsv`：第一次完整运行，暴露 generator 重复 helper 和参考 FDIV 假阳性。
- `summary_after_generator_fix.tsv`：10 个受影响 case 均恢复链接。
- `summary_after_fdiv_fix.tsv`：除 BasicMath 和 iirdf1 中途的 FCVT 假阳性外，其余均运行到 legacy 自检。
- `FilteringFunction__iirdf1__riscv_fir.after_fcvt_fix.run.log`：FCVT reference 修复后，iirdf1 完整运行到所有 SNR failure。
- `legacy_14_host_20260811/summary.tsv`：host 12 PASS、2 个 q15 failure。

## 修复优先级

1. 已完成：编译 ISA 收窄为 RV32IMF，f32 helper 改用 float，f64 保持 skipped。
2. 修正 `int64.c` 的 endian word layout，并增加 RV32 target 上的 64 位 signed/unsigned div/rem 单元测试。
3. 已完成根因修复：该首错属于 ZirconSim 非对齐内存访问模型，不是 RTL 双 LSU；保留最近 8 周期 LSU trace 作为回归诊断。
4. 单独处理 host 也失败的 LMS/NLMS q15 输入范围或 reference scaling。
