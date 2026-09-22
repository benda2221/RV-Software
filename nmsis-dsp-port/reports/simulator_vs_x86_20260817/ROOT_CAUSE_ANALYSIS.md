# NMSIS-DSP Simulator 与 x86 不一致 case 归因

日期：2026-08-17

## 后续修正与复测

2026-08-17 已修正本文第 1 类和第 3 类测试问题：结果哈希现在只覆盖算法实际定义并
写入的输出区间，RV32IMF 标量矩阵乘不再哈希未使用 scratch，四个 FIR Benchmark 的
随机系数生成长度从 `TEST_LENGTH_SAMPLES` 改为 `NUM_TAPS`。

在 `rv32imf`、`-unaligned-scalar-mem`、纯 Simulator 配置下重新运行完整 Benchmark
比较后，这两类涉及的 26 个 case 全部由 `MISMATCH` 转为 `MATCH`。FilteringFunctions
现只剩 5 个严格对齐 packed-Q15 不一致和 1 个 `lms_f32` NaN 位模式不一致；
MatrixFunctions 的 32 个 case 全部匹配。最新机器可读结果见
`manifests/benchmark_result_compare.csv`，摘要见 `manifests/BENCHMARK_RESULT_COMPARE.md`。

## 结论

基线比较中的 41 个哈希不一致 case 已全部归因。它们不是同一种编译器或 bundle
错误，可排他地分为以下 6 类：

| 类别 | 数量 | 性质 |
| --- | ---: | --- |
| 哈希包含未初始化或无效输出区间 | 22 | 比较框架假阳性 |
| 严格对齐下执行跨 word 的 32 位 Q15 访问 | 5 | 程序/移植层违反严格对齐契约，Simulator 不模拟跨 word 非对齐访问 |
| Benchmark 生成系数时数组越界 | 4 | 测试程序未定义行为，x86 结果不是有效 oracle |
| RV32 软件 64 位除法的高低 word 布局错误 | 8 | 目标运行时实现错误 |
| `sin_cos_q31` 对负数执行有符号左移 | 1 | 算法源代码未定义行为，host/target 可合法地产生不同结果 |
| `lms_f32` 的 NaN 位模式不同 | 1 | 数值分类一致，仅逐字节哈希不等 |
| **合计** | **41** | |

因此，不能把 41 个 case 都归因于 VLIW 打包、bundle 快照语义或生命周期处理。

## 完整 case 映射

### 1. 哈希覆盖未初始化区域：22 个

以下 case 在目标端和 x86 端都增加 `-ftrivial-auto-var-init=zero` 后，哈希全部一致：

- `convPartial_riscv_conv_partial_fast_q31`
- `convPartial_riscv_conv_partial_opt_q7`
- `convPartial_riscv_conv_partial_q15`
- `convPartial_riscv_conv_partial_q31`
- `convPartial_riscv_conv_partial_q7`
- `conv_iscv_conv_fast_opt_q15`
- `conv_riscv_conv_fast_q31`
- `conv_riscv_conv_opt_q15`
- `conv_riscv_conv_opt_q7`
- `conv_riscv_conv_q15`
- `conv_riscv_conv_q31`
- `conv_riscv_conv_q7`
- `correlate_riscv_correlate_fast_opt_q15`
- `correlate_riscv_correlate_fast_q31`
- `correlate_riscv_correlate_opt_q15`
- `correlate_riscv_correlate_opt_q7`
- `correlate_riscv_correlate_q15`
- `correlate_riscv_correlate_q31`
- `correlate_riscv_correlate_q7`
- `firDecimate_riscv_fir_decimate_q15`
- `firDecimate_riscv_fir_decimate_q31`
- `matMult_riscv_mat_mult_q15`

原因分别为：

1. 普通 convolution 输出有效长度为 `srcALen + srcBLen - 1`，correlation 为
   `2 * max(srcALen, srcBLen) - 1`，但测试数组按更大长度分配，结果哈希却覆盖整个
   数组。例如 `test_riscv_conv_q15.c` 第 24 行分配 `2 * max(...)`，第 41 行哈希
   整个数组，尾部未被算法写入。
2. partial convolution 只写 `pDst[firstIndex ... firstIndex + numPoints - 1]`。当前
   Q15 数据为 `firstIndex=4`、`numPoints=128`，测试却哈希整个 2048 元素数组。
3. decimator 只产生 `blockSize / M` 个输出。当前 `blockSize=1024`、`M=64`，即只写
   16 个元素，但测试哈希 1024 个元素。
4. 当前 RV32IMF 构建没有启用 `RISCV_MATH_DSP`。`riscv_mat_mult_q15` 的标量路径
   明确 `(void)pState`，不会写 scratch；测试仍把 `q15_output_back` 整体纳入哈希。

这些 case 的有效输出不一定有错；原始不一致来自不同栈布局中的未初始化字节。

### 2. 严格对齐访问契约：5 个

- `convPartial_riscv_conv_partial_fast_opt_q15`
- `convPartial_riscv_conv_partial_fast_q15`
- `convPartial_riscv_conv_partial_opt_q15`
- `conv_riscv_conv_fast_q15`
- `correlate_riscv_correlate_fast_q15`

这 5 个 case 在两侧清零自动变量后仍不一致。共同特征是用
`read_q15x2`/`write_q15x2` 把两个 Q15 元素作为一个 32 位 word 访问，同时算法又按
一个 Q15 元素滑动指针。例如 `riscv_conv_partial_opt_q15.c` 在打包读取后执行
`pScratch1 += 1U`。因此每隔一次迭代就会在 `4n+2` 地址进行 32 位访问。

当前编译参数明确关闭非对齐标量内存访问：

```text
-march=rv32imf
-mattr=+m,+f,-d,-unaligned-scalar-mem
```

但移植宏把上述操作表达成对 `int32_t *` 的 load/store，IR 因类型强制带 4 字节
对齐，后端不会把它拆为半字访问。`conv_riscv_conv_fast_q15` 已追踪到对 `4n+2`
地址执行 `sw`。

reference Simulator 的 `refMemoryRead` 只从当前 word 右移取值；`refMemoryWrite` 也只
修改当前 word，均不会与下一个 word 合并。跨 word 的非对齐 LW/SW 因而与 x86 的
非对齐内存语义不同。这里的首要问题是测试程序/移植层违反严格对齐访问契约；若仍要
支持这类程序，则必须在编译器/移植宏中把访问合法化，或者明确扩展硬件和 Simulator
的非对齐访问语义。

`conv_riscv_conv_fast_q15` 的指令级证据另见
`../strict_alignment_20260817/FILTERING_CONV_FAST_Q15_UNALIGNED_SW.md`。

### 3. Benchmark 系数数组越界：4 个

- `firDecimate_riscv_fir_decimate_fast_q15`
- `firDecimate_riscv_fir_decimate_fast_q31`
- `firLattice_riscv_fir_lattice_q15`
- `firLattice_riscv_fir_lattice_q31`

四个测试都把 `TEST_LENGTH_SAMPLES` 作为系数数组长度传给随机生成器：

```c
generate_rand_q15(firCoeffLP_q15, TEST_LENGTH_SAMPLES);
generate_rand_q31(firCoeffLP_q31, TEST_LENGTH_SAMPLES);
```

实际常量为：

| case | `TEST_LENGTH_SAMPLES` | 系数数组实际长度 `NUM_TAPS` | 越界写元素数 |
| --- | ---: | ---: | ---: |
| fir decimate q15/q31 | 1024 | 256 | 768 |
| fir lattice q15/q31 | 1024 | 32 | 992 |

越界写会破坏相邻全局对象，最终结果取决于编译器和链接器对全局变量的布局。增加自动
变量清零后，用当前 LLVM 工具链编译 x86 host，四个 case 与目标端恰好一致：

| case | Simulator | LLVM x86 host | GCC x86 host |
| --- | --- | --- | --- |
| fir decimate fast q15 | `0xa220a3b4` | `0xa220a3b4` | `0xb621b4ea` |
| fir decimate fast q31 | `0x7f3b81fe` | `0x7f3b81fe` | `0x598f3a71` |
| fir lattice q15 | `0x08ec3db0` | `0x08ec3db0` | `0xe3dd62d1` |
| fir lattice q31 | `0x1dcc3912` | `0x1dcc3912` | `0x2198012c` |

这只说明同一 LLVM 工具链形成了相似内存布局，不代表结果正确。由于源程序已经越界，
GCC 和 LLVM 的任一结果都不能作为标准答案。UBSan 还在这些算法路径中发现有符号溢出
或负数左移，例如 fast decimate q15 第 487 行、fast decimate q31 第 417 行以及
fir lattice q31 第 426 行。

### 4. RV32 软件 64 位除法：8 个

- `atan2_riscv_atan2_q31`
- `divide_riscv_divide_q31`
- `rms_riscv_rms_q15`
- `rms_riscv_rms_q31`
- `std_riscv_std_q15`
- `std_riscv_std_q31`
- `var_riscv_var_q15`
- `var_riscv_var_q31`

这些路径在 RV32 上都会使用 `__divdi3` 或 `__udivdi3`。当前
`RV-Software/base-port/tool/src/int64.c` 第 11–19 行把 64 位数拆成：

```c
struct {
    su_int high;
    su_int low;
} s;
```

RISC-V 当前为 little-endian，union 中低地址的第一个 32 位成员应当是 `low`，当前
定义正好相反。后续 `__udivmoddi4` 把 `n.s.high`、`n.s.low` 和 `d.s.high`、
`d.s.low` 当作真实高低 word 使用，因此商和余数计算错误。

`riscv_divide_q31` 直接受 `__divdi3` 影响；`riscv_atan2_q31` 调用前者；六个统计函数
则使用无符号 64 位除法。这 8 个是确定的目标运行时实现错误，不是 x86 oracle 或
Simulator 内存模型造成的假阳性。

### 5. `sin_cos_riscv_sin_cos_q31`：C 未定义行为

`riscv_sin_cos_q31.c` 第 81、83、99、101 行存在类似表达式：

```c
((q63_t)Df << 32)
((q63_t)d1 << 1)
```

`Df` 或 `d1` 可以为负。C 语言中对负的有符号整数左移是未定义行为。UBSan 已在当前
输入上精确报告第 81 行 `left shift of negative value -161701`。因此 GCC x86 与
目标 LLVM 产生不同结果并不能证明 Simulator 或编译器后端错误。

CPU/Simulator difftest 中两侧都得到 `0xd7268d8d`，而 GCC/LLVM x86 host 都得到
`0xadb79d47`。目标 RTL 和 reference Simulator 对已生成目标程序的行为一致。

复测命令：

```bash
cd /home/zhangfulin/RISCV-VLIW/Zircon-VLIW/RV-Software/nmsis-dsp-port
make TEST_SYSTEM=benchmark \
  SUITE=ControllerFunctions \
  TEST_CASE=sin_cos_riscv_sin_cos_q31 \
  USE_SIMULATOR_ONLY_MODE=0 \
  ARGS=50000000 run
```

### 6. `lms_riscv_lms_f32`：NaN 编码不同

目标端和 x86 端的输入数组、参考数组和系数数组哈希完全相同。逐元素比较输出和 error
数组得到：

- 下标 `0..487`：两侧逐 bit 完全相同；
- 下标 `488..1023`：两侧都已经是 quiet NaN；
- RISC-V/Simulator：`0x7fc00000`，即 canonical NaN；
- x86 host：`0xffc00000`，即带负号的 quiet NaN。

536 个元素的 NaN 位模式不同，造成最终 FNV 字节哈希分别为：

```text
Simulator/CPU: 0x22050801
x86 host:      0xdc1d1401
```

RISC-V F 扩展算术结果采用 canonical NaN；当前 Simulator 的
`stageFloatArithmeticWrite` 也显式规范化为 `0x7fc00000`，RTL/Simulator difftest 完整
通过。因此这不是 Simulator 算术错误，而是比较脚本把语义上同为 NaN 的不同位表示当成
了结果不一致。若测试目标是数值等价，比较前应规范化 NaN；若测试目标是 RISC-V 位级
行为，则应以 canonical NaN 为期望值，不能用 x86 原始 NaN payload/sign 作 oracle。

复测命令：

```bash
cd /home/zhangfulin/RISCV-VLIW/Zircon-VLIW/RV-Software/nmsis-dsp-port
make TEST_SYSTEM=benchmark \
  SUITE=FilteringFunctions \
  TEST_CASE=lms_riscv_lms_f32 \
  USE_SIMULATOR_ONLY_MODE=0 \
  ARGS=10000000 run
```

## 对原始 41 个不一致的重新解读

如果只统计“有效输出确实暴露目标侧问题”的 case：

- 5 个 Q15 case 暴露严格对齐配置与 packed Q15 访问之间的契约冲突；
- 8 个 q15/q31 case 暴露 RV32 软件 64 位除法实现错误；
- 合计 13 个。

其余 28 个不能据原始 hash 判定编译器或 Simulator 错误：22 个哈希了未初始化区，4 个
测试程序越界，1 个依赖 C 未定义行为，1 个只是 NaN 位模式不同。

## 初次归因阶段的修改范围

初次归因阶段只进行了诊断运行并新增本报告。用于定位 `lms_f32` 的临时输入/逐元素打印
插桩已撤销；当时没有修改 LLVM、NMSIS 算法、移植层、RTL 或 Simulator 实现。之后的
测试 case 与结果哈希修正记录见文首“后续修正与复测”。
