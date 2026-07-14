# NMSIS DSP Zircon Test Porting Status

本文档记录当前 NMSIS DSP 测试系统移植到 Zircon 可执行测试的状态。机器可读清单见 `manifests/dsp_test_plan.csv`，生成摘要见 `manifests/ZIRCON_TEST_PLAN.md`。

## 已做改动

- 增加 `scripts/generate_zircon_tests.py`，从 `vendor/NMSIS/DSP` 生成 Zircon 可执行测试清单、`sources.mk`、benchmark suite 列表和 `dsp_test_plan.csv`。
- 扩展顶层 `Makefile`，支持 `TEST_SYSTEM=benchmark`、`TEST_SYSTEM=legacy` 和 `TEST_SYSTEM=testing-smoke` 测试入口。
- Benchmark runner/dependency 自动生成会扫描 NMSIS `Benchmark/*/test_*.c`，按代码中的 `riscv_*` 符号闭包拉入所需 `Source/**/*.c`，并忽略注释中的伪引用。
- 已为 `riscv_boolean_distance.c` 中由模板宏生成的 `riscv_boolean_distance_*` helper 建立显式符号索引，修复 boolean distance benchmark 的 dependency closure。
- Benchmark `f32` case 已全部启用；另外已单独验证并启用一批非 f16/f64 的 q15/q31 controller/filtering、boolean distance、float/fixed conversion case。
- `Benchmark/ControllerFunctions/test_riscv_pid_q15.c` 保持 skipped，但生成单 case runner，便于复现当前 Dandelion VLIW 后端错误。
- 增加 `port/src/compat_runtime.c`，提供当前测试需要的最小运行时兼容层，包括 deterministic `srand/rand`、简单 `malloc/free`、`abs/labs` 和少量 math stub。
- 增加 `port/src/legacy_basicmath_fixed_runner.c`，把上游 legacy `Test/BasicMathFunctions` 改造成 Zircon 可运行的 fixed-point runner。
- 增加 `port/src/ref_matrix_f32_subset.c`，只补齐上游 `common.h` 隐式引用到的 f32 matrix reference 函数，避免拉入完整 matrix reference 后触发额外 libm/f64 依赖。
- 对所有 legacy C 源生成 per-case 可执行入口。源文件若自带 `main`，使用上游 `main`；没有 `main` 的 reference/helper 源使用 compile-link smoke runner。
- 对所有 skipped case 做过临时 probe。legacy 源文件若自带 `main`，probe 时不再额外链接临时 runner，从而消除 `duplicate symbol: main` 这个 harness 误报，并暴露真实的编译或运行失败。

## 当前支持

当前 generator 输出统计：

- `enabled`: 401
- `skipped`: 295

按 system 统计：

- `benchmark enabled`: 336
- `benchmark skipped`: 122
- `legacy enabled`: 64
- `testing skipped`: 98
- `testing_benchmark skipped`: 75
- `testing_smoke enabled`: 1

当前 Benchmark enabled 按 suite 统计：

```text
BasicMathFunctions: 51
BayesFunctions: 1
ComplexMathFunctions: 19
ControllerFunctions: 12
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

复现当前保留 skipped 的后端编译错误 case：

```bash
make TEST_SYSTEM=benchmark SUITE=ControllerFunctions TEST_CASE=pid_riscv_pid_q15 clean run
```

该 case 当前在 `llc` 的 `RISCV Packet Padding` pass 中失败：

```text
LLVM ERROR: Dandelion VLIW instruction has no legal slot
Running pass 'RISCV Packet Padding' on function '@pid_riscv_pid_q15'
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

`nmsis-dsp-port` 默认 `USE_SIMULATOR_ONLY_MODE=1`，因此 f32 Benchmark runner 默认绕过当前 F-instruction difftest 路径。若要验证 difftest 路径，可显式覆盖：

```bash
USE_SIMULATOR_ONLY_MODE=0 make TEST_SYSTEM=benchmark SUITE=FastMathFunctions run
```

## 当前不支持的测试和原因

### Benchmark 剩余 skipped

当前 `benchmark` 剩余 122 个 skipped：

```text
float16;floating_point: 84
floating_point: 38
```

其中 `float16;floating_point` 是 f16 路径；`floating_point` 主要是 f64 路径，另包含 `test_riscv_pid_q15.c` 这个已知 Dandelion VLIW 后端 codegen 错误 case。

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

### f64 和完整 libm

Benchmark f32 当前可以在 simulator-only 模式下执行，但 f64 和完整 libm 仍不是当前 port 的支持边界。当前 `compat_runtime.c` 只提供很小的 stub，不是完整 libm。

缺失支持：

- f64 ABI、运行时和 reference 验证路径。
- `sqrt/sqrtf`、`sin/sinf`、`cos/cosf`、`log/logf/log10`、`exp/expf`、`pow/powf`、`floor/ceil/atan2` 等完整实现。
- 对 f32/f64 数值误差和 reference 阈值的确认。
- target 侧浮点 ABI、soft-float/hard-float 路径和 difftest 行为确认。


### Legacy generated cases 和 probe 结果

当前 generator 已为全部 63 个上游 legacy C 源生成 per-case 可执行入口，manifest 中 legacy skipped 已清零。另保留 1 个 Zircon fixed BasicMath runner，因此 `legacy enabled` 总数为 64。

历史 probe 中有 19 个 case 报 `ld.lld: error: duplicate symbol: main`，根因是 probe harness 额外生成了 `runner.c`，而这些上游 legacy 源文件本身已经定义 `main`。修正策略后，这些 case 改为直接使用上游源文件自带 `main` 作为入口，并补齐 `compat_runtime.c`、NMSIS common tables、必要 algorithm source 和 reference helper 依赖。`duplicate symbol: main` 已全部消除，新的结果为：

```text
PASS: 4
compile_error: 1
runtime_test_failure: 14
```

通过的 case：

- `vendor/NMSIS/DSP/Test/BayesianFunctions/riscv_bayesian.c`
- `vendor/NMSIS/DSP/Test/FilteringFunction/levinsonDurbin/riscv_fir.c`
- `vendor/NMSIS/DSP/Test/MatrixFunctions/f16Part/riscv_matrix.c`
- `vendor/NMSIS/DSP/Test/SVMFunctions/riscv_svm.c`

仍失败的真实原因：

- `vendor/NMSIS/DSP/Test/ConvolutionFunctions/riscv_conv.c`: 需要的 `ref_riscv_conv.c` 存在非 `void` 函数缺少 return，被 `-Werror,-Wreturn-type` 提升为编译错误。
- `vendor/NMSIS/DSP/Test/BasicMathFunctions/riscv_basic_math_functions.c`: unsigned logical 子测 `riscv_and/or/not/xor_u8/u16` 运行结果 mismatch。
- `vendor/NMSIS/DSP/Test/DistanceFunctions/riscv_distance.c`: `riscv_minkowski_distance_f32` 运行结果 mismatch。
- `vendor/NMSIS/DSP/Test/FilteringFunction/LMSPart/riscv_fir.c`: `riscv_lms_f32/q31/q15` SNR failure。
- `vendor/NMSIS/DSP/Test/FilteringFunction/NLMSPart/riscv_fir.c`: `riscv_lms_norm_f32/q31/q15` SNR failure。
- `vendor/NMSIS/DSP/Test/FilteringFunction/firDecimatorPart/riscv_fir.c`: FIR decimator f32/q31/q15/fast SNR failure。
- `vendor/NMSIS/DSP/Test/FilteringFunction/firInterpolatePart/riscv_fir.c`: FIR interpolate f32/q31/q15 SNR failure。
- `vendor/NMSIS/DSP/Test/FilteringFunction/firLatticePart/riscv_fir.c`: FIR lattice f32/q31/q15 SNR failure。
- `vendor/NMSIS/DSP/Test/FilteringFunction/firSparsePart/riscv_fir.c`: FIR sparse f32/q31/q15/q7 SNR failure。
- `vendor/NMSIS/DSP/Test/FilteringFunction/iirLatticePart/riscv_fir.c`: IIR lattice f32/q31/q15 SNR failure。
- `vendor/NMSIS/DSP/Test/FilteringFunction/iirdf1/riscv_fir.c`: biquad df1 f32/q31/q15/fast/32x64 SNR failure。
- `vendor/NMSIS/DSP/Test/FilteringFunction/iirdf2t/riscv_fir.c`: biquad df2T f32/stereo SNR failure。
- `vendor/NMSIS/DSP/Test/QuaternionMathFunctions/riscv_quaternion.c`: `riscv_rotation2quaternion_f32` 运行结果 mismatch。
- `vendor/NMSIS/DSP/Test/StatisticsFunctions/riscv_statistics.c`: `riscv_var_q31`、`riscv_std_q15`、`riscv_var_q15`、`riscv_entropy_f64`、`riscv_kullback_leibler_f64` 运行结果 mismatch。
- `vendor/NMSIS/DSP/Test/TransformFunction/cfft/riscv_tranform.c`: cfft f32/q31/q15 和 radix2/radix4 变体 SNR failure。

这里的 SNR failure 是运行后的数值正确性失败：target 输出与 reference 输出的信噪比低于 legacy 测试阈值。它不是编译、链接或后端 codegen 失败。

### Zircon difftest FPR 支持方案

当前 Zircon difftest 只检查 VLIW pack 起始 PC 和 GPR 写回值。硬件 debug 口已经暴露 FPR 写回所需信息：`wbValid`、`wbPC`、`wbInst`、`wbRd` 和 `wbData`，其中 `wbRd[5]` 区分 GPR/FPR，`wbRd[4:0]` 是寄存器号，`wbData` 是 32-bit 写回数据。当前 `Emulator.cc` 在提交比对循环中跳过了 FPR 写回。

建议实现步骤：

1. 在 `Simulator` 中增加 `getFprBits(uint8_t rd)`，用 `memcpy` 将 reference `float fpr[rd]` 取出为 `uint32_t` 原始位模式。
2. 在 `Emulator` 中增加 `difftestFPR(uint8_t rd, uint32_t rdData, uint32_t pc)`，比较 DUT `wbData` 与 reference `getFprBits(rd)`。
3. 修改 `Emulator` 的提交比对循环：GPR 继续跳过 `x0`；FPR 不跳过 `f0`；报错信息区分 `RF mismatch` 和 `FPR mismatch`。
4. 第一阶段只比较 FPR 写回结果，不比较 `fflags`。如果后续要完整验证浮点异常状态，需要扩展 debug IO 暴露 `fflags`，并让 reference simulator 维护 `NV/DZ/OF/UF/NX`。

FPR bit compare 适合作为第一阶段 difftest 增强；如果目标是严格验证浮点执行正确性，应进一步将 reference simulator 改为维护 `uint32_t` FPR 位模式，并引入 SoftFloat 或等价的 RISC-V/IEEE754 reference，实现结果 bit 和 `fflags` 的精确建模。

### 原始 legacy BasicMath main

上游原始 `vendor/NMSIS/DSP/Test/BasicMathFunctions/riscv_basic_math_functions.c` 没有直接作为 Zircon runner 启用，而是由 `port/src/legacy_basicmath_fixed_runner.c` 替代。

原因：

- 原始 main 同时执行 f32 和 fixed-point 测试；当前 f32 子测会在 `flt.s` 浮点比较处触发 difftest 不一致。
- 原始路径中的 unsigned logical 子测在 legacy runner 场景下曾触发 `lbu` difftest mismatch。

当前处理：

- legacy runner 保留 q7/q15/q31 数值类测试。
- legacy runner 暂时跳过 unsigned logical 组。
- Benchmark BasicMath 的 unsigned logical 组已经通过 Zircon simulator 验证。

### RVV/vector 路径

RVV/vector 相关条目当前不进入可执行子集。

缺失支持：

- Zircon 当前目标和模拟器对 RVV 指令、寄存器状态和 difftest 的完整支持确认。
- RVV 编译选项、NMSIS vector 宏和 source variant 选择规则。

## 后续补齐顺序建议

1. 修复 `Benchmark/ControllerFunctions/test_riscv_pid_q15.c` 触发的 `Dandelion VLIW instruction has no legal slot` 后端问题。
2. 确认 f32 指令 difftest 行为，再将 f32 Benchmark 从 simulator-only 验证推进到 difftest 验证。
3. 对 generated legacy case 中已经越过 `main` 冲突的 case，优先区分 reference/helper 适配问题和真实算法数值问题。
4. 引入 f64 ABI/runtime 和完整 libm，再启用 f64 及 libm-heavy 测试。
5. 确认或恢复 legacy 场景下 unsigned logical 组。
6. 建立 C++ runtime/STL shim 后，再启用 `Testing` C++ 测试系统。
