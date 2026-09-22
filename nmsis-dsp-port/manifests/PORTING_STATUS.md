# NMSIS DSP Zircon Test Porting Status

本文档记录当前 NMSIS DSP 测试系统移植到 Zircon 可执行测试的状态。机器可读清单见 `manifests/dsp_test_plan.csv`，生成摘要见 `manifests/ZIRCON_TEST_PLAN.md`。

## 已做改动

- 增加 `scripts/generate_zircon_tests.py`，从 `vendor/NMSIS/DSP` 生成 Zircon 可执行测试清单、`sources.mk`、benchmark suite 列表和 `dsp_test_plan.csv`。
- 扩展顶层 `Makefile`，支持 `TEST_SYSTEM=benchmark`、`TEST_SYSTEM=legacy` 和 `TEST_SYSTEM=testing-smoke` 测试入口。
- Benchmark runner/dependency 自动生成会扫描 NMSIS `Benchmark/*/test_*.c`，按代码中的 `riscv_*` 符号闭包拉入所需 `Source/**/*.c`，并忽略注释中的伪引用。
- 已为 `riscv_boolean_distance.c` 中由模板宏生成的 `riscv_boolean_distance_*` helper 建立显式符号索引，修复 boolean distance benchmark 的 dependency closure。
- Benchmark `f32` case 已全部启用；另外已单独验证并启用一批非 f16/f64 的 q15/q31 controller/filtering、boolean distance、float/fixed conversion case。
- `Benchmark/ControllerFunctions/test_riscv_pid_q15.c` 在 inline asm/solo fence 打包修复后已重新编译并通过 difftest，现已启用。
- 增加 `port/src/compat_runtime.c`，提供当前测试需要的最小运行时兼容层，包括 deterministic `srand/rand`、简单 `malloc/free`、`abs/labs` 和少量 math stub。
- 增加 `port/src/legacy_basicmath_fixed_runner.c`，把上游 legacy `Test/BasicMathFunctions` 改造成 Zircon 可运行的 fixed-point runner。
- 增加 `port/src/ref_matrix_f32_subset.c`，只补齐上游 `common.h` 隐式引用到的 f32 matrix reference 函数，避免拉入完整 matrix reference 后触发额外 libm/f64 依赖。
- 对所有 legacy C 源生成 per-case 可执行入口。源文件若自带 `main`，使用上游 `main`；没有 `main` 的 reference/helper 源使用 compile-link smoke runner。
- 对所有 skipped case 做过临时 probe。legacy 源文件若自带 `main`，probe 时不再额外链接临时 runner，从而消除 `duplicate symbol: main` 这个 harness 误报，并暴露真实的编译或运行失败。

## 当前支持

当前 generator 输出统计：

- `enabled`: 402
- `skipped`: 294

按 system 统计：

- `benchmark enabled`: 337
- `benchmark skipped`: 121
- `legacy enabled`: 64
- `testing skipped`: 98
- `testing_benchmark skipped`: 75
- `testing_smoke enabled`: 1

当前 Benchmark enabled 按 suite 统计：

```text
BasicMathFunctions: 51
BayesFunctions: 1
ComplexMathFunctions: 19
ControllerFunctions: 13
DistanceFunctions: 18
FastMathFunctions: 18
FilteringFunctions: 67
InterpolationFunctions: 9
MatrixFunctions: 32
QuaternionMathFunctions: 8
SVMFunctions: 4
StatisticsFunctions: 57
SupportFunctions: 24
TransformFunctions: 16
```

另外仍支持：

- `Test/BasicMathFunctions`: Zircon fixed-point runner，共 30 个 q7/q15/q31 reference checks。
- `Test/**/*.c`: 每个上游 legacy C 文件都有 `generated/legacy/<suite>/cases/<case>/sources.mk` 单 case 入口；自带 `main` 的源使用上游入口，没有 `main` 的 reference/helper 源使用 compile-link smoke runner。
- `Testing/BasicMaths`: Q7/Q15/Q31 pattern-driven smoke runner，不做完整数值断言。

legacy 测试保留随机数据路径。`compat_runtime.c` 提供 `srand/rand`，legacy runner 会调用上游 `generate_rand_q7/q15/q31`。

## 如何运行

在 `nmsis-dsp-port` 目录下运行：

```bash
python3 scripts/generate_zircon_tests.py
```

运行 Benchmark suite：

```bash
make run-benchmark SUITE=BasicMathFunctions
make TEST_SYSTEM=benchmark SUITE=DistanceFunctions run
```

运行单个 Benchmark case：

```bash
make TEST_SYSTEM=benchmark SUITE=DistanceFunctions TEST_CASE=dice_distance_riscv_dice_distance clean run
```

运行此前触发 packetizer 错误、当前已经通过的 pid_q15 case：

```bash
make TEST_SYSTEM=benchmark SUITE=ControllerFunctions TEST_CASE=pid_riscv_pid_q15 clean run
```

当前结果：

```text
PASS benchmark/ControllerFunctions/riscv_pid_q15
SIMULATION ENDED SUCCESSFULLY.
```

运行 legacy Test BasicMath fixed runner：

```bash
make run-legacy SUITE=BasicMathFunctions
```

运行单个 generated legacy case：

```bash
make TEST_SYSTEM=legacy SUITE=BayesianFunctions TEST_CASE=riscv_bayesian clean run
make TEST_SYSTEM=legacy SUITE=BasicMathFunctions TEST_CASE=ref_basic_math_functions clean run
```

连续运行所有 generated legacy case：

```bash
make run-legacy-generated-all
```

注意：该批量目标会在第一个失败 case 处停止；当前部分 legacy case 预期仍会暴露 reference 编译错误或运行期数值/SNR mismatch。

连续运行当前默认支持的 benchmark 套件、legacy BasicMath 和 testing smoke：

```bash
make test-all
```

`nmsis-dsp-port` 默认 `USE_SIMULATOR_ONLY_MODE=1`。若要同时比较 GPR 和 FPR 写回，可显式覆盖：

```bash
USE_SIMULATOR_ONLY_MODE=0 make TEST_SYSTEM=benchmark SUITE=FastMathFunctions run
```

## 当前不支持的测试和原因

### Benchmark 剩余 skipped

当前 `benchmark` 剩余 121 个 skipped：

```text
float16;floating_point: 84
floating_point: 37
```

其中 `float16;floating_point` 是 f16 路径，`floating_point` 是尚未支持的 f64 路径。`test_riscv_pid_q15.c` 已不在 skipped 集合中。

### Testing C++ 测试系统

`NMSIS/DSP/Testing` 下的 `Source/Tests/*.cpp` 和 `Source/Benchmarks/*.cpp` 已全部清点到 manifest，但当前全部标记为 `cpp_runtime_gap`。

缺失支持：

- C++ 编译入口。
- C++ 标准库头文件和运行时支持，例如 `cstdio`、`vector`、`string`、异常/构造析构相关 runtime。
- Testing 框架依赖的 host/target 适配层。
- Pattern 数据装载和结果输出约定的 Zircon 适配。

### float16

manifest 中 `float16` 相关条目当前跳过。

缺失支持：

- 目标侧 `_Float16`/float16 ABI 的确认。
- NMSIS `RISCV_FLOAT16_SUPPORTED` 路径所需的编译器、头文件和运行时支持。
- 对应 f16 reference/verify 的 Zircon 运行验证。

### f64、RV32D 和完整 libm

f64 和完整 libm 仍不是当前 port 的支持边界。编译选项已经与 RTL/Simulator 对齐：Clang 和 assembler 使用 `-march=rv32imf`，LLC 使用 `-mattr=+m,+f,-d`。f32 helper 使用 `1.0f`、`log10f` 等 float 路径；double wrapper 和 f64 reference helper 仅在显式定义 `ZIRCON_ENABLE_FLOAT64` 时编译。manifest 中 37 个 f64 benchmark case 继续 skipped。

缺失支持：

- RV32D 的 RTL decode/执行、64-bit FPR 模型、f64 ABI、运行时和 reference 验证路径。
- `sqrt/sqrtf`、`sin/sinf`、`cos/cosf`、`log/logf/log10`、`exp/expf`、`pow/powf`、`floor/ceil/atan2` 等完整实现。
- 对 f32/f64 数值误差和 reference 阈值的确认。
- target 侧浮点 ABI、soft-float/hard-float 路径和 difftest 行为确认。


### Legacy generated cases 和 probe 结果

当前 generator 已为全部 63 个上游 legacy C 源生成 per-case 可执行入口，manifest 中 legacy skipped 已清零。另保留 1 个 Zircon fixed BasicMath runner，因此 `legacy enabled` 总数为 64。

历史 probe 中有 19 个 case 报 `duplicate symbol: main`，根因是 probe harness 对自带 `main` 的源又生成了 runner，该问题已消除。本轮还修复了 generator 对嵌套源中 `#include "../HelperFunctions/*.c"` 的解析：scanner 现在按 Makefile 的 include roots 识别文本包含的 C 文件，不再把同一 helper 作为独立翻译单元重复链接。

2026-08-11 对此前列出的 14 个 runtime failure 重新编译，并以 `USE_SIMULATOR_ONLY_MODE=0` 逐一运行。参考模拟器的 `FDIV.S` 零除语义和 `FCVT.W.S/WU.S` 越界语义修正后，当时结果为：

```text
target difftest first-error: 1  (BasicMath dual-LSU lbu)
target legacy main returned nonzero: 13
host control PASS: 12
host control q15 failure: 2       (LMS/NLMS)
```

逐例结果和根因证据见 `manifests/LEGACY_14_FAILURE_ANALYSIS.md`，机器可读结果见 `manifests/legacy_14_results.csv`。2026-08-12 已把编译目标收窄为 RV32IMF，并针对唯一的 difftest 首错重新清理、编译和运行。当前结论：

- BasicMath 的 slot 6 `lbu` 首错不是 RTL 双 LSU 问题。LSU1 地址正确，读到 0 是因为更早一次对非对齐 `q7_out_array` 的 `sw` 被 DUT AXIMemory 错误加掩码，清除了相邻 `q7_b[125:126]`。DUT/reference 改为逐字节、可跨 word 的 load/store 后，原始 BasicMath 完整 difftest PASS（386510 cycles，1438512 instructions）。
- RV32D 配置不一致已经消除；BasicMath ELF 属性只含 RV32IMF，反汇编没有 D 指令和 `__*df*` 调用。f32 随机数和 SNR helper 已完全走 float 路径，f64 继续 skipped。
- Statistics 的 var_q31/std_q15/var_q15 来自 `base-port/tool/src/int64.c` 在 little-endian ABI 下颠倒 `udwords.high/low`，破坏软件 64 位除法。
- LMS/NLMS 的 q15 子项在 host 也失败，是满幅随机输入下可独立复现的 legacy q15 数值/溢出问题；其余 12 个 host 对照全部通过。

### Zircon difftest FPR 当前状态

FPR 写回 bit compare 已实现并启用：`wbRd[5]` 区分 GPR/FPR，FPR 路径比较 DUT `wbData` 与 reference `getFprBits(rd)`，错误信息显示 `FPR mismatch`。本轮依靠该功能发现并修正了 reference 的 canonical NaN、`FDIV.S` 零除和 `FCVT.W.S/WU.S` 溢出语义。

当前仍未比较 `fflags`，reference FPR 仍以 32-bit `float` 建模，因此只覆盖 RV32F。编译 ISA 已收窄到 `rv32imf`；若将来重新启用 `+d`，必须同时扩展 64-bit FPR、RV32D 执行语义和 `fflags`。

### 原始 legacy BasicMath main

上游原始 `vendor/NMSIS/DSP/Test/BasicMathFunctions/riscv_basic_math_functions.c` 没有直接作为 Zircon runner 启用，而是由 `port/src/legacy_basicmath_fixed_runner.c` 替代。

此前使用 fixed runner 的原因：

- 原始 main 同时执行 f32 和 fixed-point 测试；旧 f32 helper 会因 RV32D 配置不一致产生无效输入/判定。
- unsigned logical loop 曾在 slot 6 `lbu` 暴露 difftest mismatch，现已确认其根因是模拟器非对齐内存模型。

当前状态：

- legacy runner 保留 q7/q15/q31 数值类测试。
- legacy runner 暂时跳过 unsigned logical 组。
- Benchmark BasicMath 的 unsigned logical 组已经通过 Zircon simulator 验证。
- 上游原始 `riscv_basic_math_functions` 已在 RV32IMF GPR/FPR difftest 下完整通过；fixed runner 可在后续清理中取消替代关系。

### RVV/vector 路径

RVV/vector 相关条目当前不进入可执行子集。

缺失支持：

- Zircon 当前目标和模拟器对 RVV 指令、寄存器状态和 difftest 的完整支持确认。
- RVV 编译选项、NMSIS vector 宏和 source variant 选择规则。

## 后续补齐顺序建议

1. 已完成：编译 ISA 与处理器统一为 RV32IMF，f32 helper 使用 float，f64 保持 skipped。
2. 修正 `base-port/tool/src/int64.c` 的 little-endian high/low 布局，增加 target 64 位 div/rem 回归。
3. 已完成：修复模拟器非对齐 load/store；原先归因于 pipeline 6/LSU1 的 BasicMath 首错已通过完整 difftest。
4. 单独处理 host 也失败的 LMS/NLMS q15 输入幅度或 reference scaling。
5. 若决定支持 f64，再实现 RV32D、64-bit FPR difftest、f64 ABI/runtime 和完整 libm。
6. 建立 C++ runtime/STL shim 后，再启用 `Testing` C++ 测试系统。
