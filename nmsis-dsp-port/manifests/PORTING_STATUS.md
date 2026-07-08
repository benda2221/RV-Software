# NMSIS DSP Zircon Test Porting Status

本文档记录当前 NMSIS DSP 测试系统移植到 Zircon 可执行测试的状态。机器可读清单见 `manifests/dsp_test_plan.csv`，生成摘要见 `manifests/ZIRCON_TEST_PLAN.md`。

## 已做改动

- 增加 `scripts/generate_zircon_tests.py`，从 `vendor/NMSIS/DSP` 生成 Zircon 可执行测试清单、`sources.mk`、benchmark suite 列表和 `dsp_test_plan.csv`。
- 扩展顶层 `Makefile`，支持 `TEST_SYSTEM=benchmark`、`TEST_SYSTEM=legacy` 和 `TEST_SYSTEM=testing-smoke` 测试入口。
- 增加 benchmark runner/dependency 自动生成：扫描 NMSIS `Benchmark/*/test_*.c`，按 `riscv_*` 符号闭包拉入所需 `Source/**/*.c`，并跳过 float/float16/RVV/libm 依赖。
- 增加 `port/src/compat_runtime.c`，提供当前测试需要的最小运行时兼容层，包括 deterministic `srand/rand`、简单 `malloc/free`、`abs/labs` 和少量 math stub。
- 增加 `port/src/legacy_basicmath_fixed_runner.c`，把上游 legacy `Test/BasicMathFunctions` 改造成 Zircon 可运行的 fixed-point runner。
- 增加 `port/src/ref_matrix_f32_subset.c`，只补齐上游 `common.h` 隐式引用到的 f32 matrix reference 函数，避免拉入完整 matrix reference 后触发额外 libm/f64 依赖。
- 生成 `generated/benchmark/<Suite>/runner.c`、`generated/benchmark/<Suite>/sources.mk` 和 `generated/benchmark/suites.mk`，作为当前可执行测试的构建入口。

## 当前支持

当前 generator 输出统计：

- `enabled`: 198
- `skipped`: 498

当前默认 `make test-all` 已验证可执行的测试：

- `Benchmark/BasicMathFunctions`: fixed-point/u8/u16/u32 子集，共 42 个函数。
- `Benchmark/ComplexMathFunctions`: q15/q31 fixed-point 子集，共 13 个函数。
- `Benchmark/ControllerFunctions`: q31 fixed-point 子集，共 2 个函数。
- `Benchmark/FastMathFunctions`: q15/q31 fixed-point 子集，共 10 个函数。
- `Benchmark/InterpolationFunctions`: q7/q15/q31 fixed-point 子集，共 6 个函数。
- `Benchmark/StatisticsFunctions`: q7/q15/q31 fixed-point 子集，共 39 个函数。
- `Benchmark/SupportFunctions`: q7/q15/q31 fixed-point 子集，共 12 个函数。
- `Test/BasicMathFunctions`: Zircon fixed-point runner，共 30 个 q7/q15/q31 reference checks。

legacy 测试保留随机数据路径。`compat_runtime.c` 提供 `srand/rand`，legacy runner 会调用上游 `generate_rand_q7/q15/q31`。

## 如何运行

在 `nmsis-dsp-port` 目录下运行：

```bash
python3 scripts/generate_zircon_tests.py
```

运行 Benchmark BasicMath：

```bash
make run-benchmark SUITE=BasicMathFunctions
```

等价的显式命令：

```bash
make TEST_SYSTEM=benchmark SUITE=BasicMathFunctions run
```

运行 legacy Test BasicMath：

```bash
make run-legacy SUITE=BasicMathFunctions
```

等价的显式命令：

```bash
make TEST_SYSTEM=legacy SUITE=BasicMathFunctions run
```

连续运行当前默认支持的 benchmark 套件和 legacy BasicMath：

```bash
make test-all
```

`make test-all` 当前会运行 `generated/benchmark/suites.mk` 中的默认 benchmark 套件，然后运行 legacy BasicMath。已验证结果包括：

```text
PASS benchmark/BasicMathFunctions count=42
PASS benchmark/ComplexMathFunctions count=13
PASS benchmark/ControllerFunctions count=2
PASS benchmark/FastMathFunctions count=10
PASS benchmark/InterpolationFunctions count=6
PASS benchmark/StatisticsFunctions count=39
PASS benchmark/SupportFunctions count=12
PASS legacy/BasicMathFunctions fixed-point count=30
SIMULATION ENDED SUCCESSFULLY
```

## 当前不支持的测试和原因

### Testing C++ 测试系统

`NMSIS/DSP/Testing` 下的 `Source/Tests/*.cpp` 和 `Source/Benchmarks/*.cpp` 已全部清点到 manifest，但当前全部标记为 `cpp_runtime_gap`。

缺失支持：

- C++ 编译入口。
- C++ 标准库头文件和运行时支持，例如 `cstdio`、`vector`、`string`、异常/构造析构相关 runtime。
- Testing 框架依赖的 host/target 适配层。
- Pattern 数据装载和结果输出约定的 Zircon 适配。

### 非默认 Benchmark/Test 套件

生成器已经能为更多普通 C benchmark 套件生成 runner 和 source dependency closure，但它们暂不全部进入默认 `test-all`。

当前暂不进入默认集合的已知原因：

- `FilteringFunctions`: 可以构建并运行，但用时很长，不适合作为默认 smoke/regression 集合。
- `MatrixFunctions`: `matCmplxMult_riscv_mat_cmplx_mult_q15` 当前触发 difftest register mismatch。
- `TransformFunctions`: 依赖表、向量/FFT 路径和运行时间仍需单独确认。
- 其它 suite 仍主要受 float/float16/RVV/libm/C++ runtime 限制。

### float16

manifest 中 `float16` 相关条目当前跳过。

缺失支持：

- 目标侧 `_Float16`/float16 ABI 的确认。
- NMSIS `RISCV_FLOAT16_SUPPORTED` 路径所需的编译器、头文件和运行时支持。
- 对应 f16 reference/verify 的 Zircon 运行验证。

### libm 和浮点 math

manifest 中 `libm` 相关条目当前跳过。当前 `compat_runtime.c` 只提供很小的 stub，不是完整 libm。

缺失支持：

- `sqrt/sqrtf`、`sin/sinf`、`cos/cosf`、`log/logf/log10`、`exp/expf`、`pow/powf`、`floor/ceil/atan2` 等完整实现。
- 对 f32/f64 数值误差和 reference 阈值的确认。
- target 侧浮点 ABI、soft-float/hard-float 路径和 difftest 行为确认。

### Zircon difftest FPR 支持方案

当前 Zircon difftest 只检查 VLIW pack 起始 PC 和 GPR 写回值。硬件 debug 口已经暴露 FPR 写回所需信息：`wbValid`、`wbPC`、`wbInst`、`wbRd` 和 `wbData`，其中 `wbRd[5]` 区分 GPR/FPR，`wbRd[4:0]` 是寄存器号，`wbData` 是 32-bit 写回数据。当前 `Emulator.cc` 在提交比对循环中跳过了 FPR 写回。

建议实现步骤：

1. 在 `Simulator` 中增加 `getFprBits(uint8_t rd)`，用 `memcpy` 将 reference `float fpr[rd]` 取出为 `uint32_t` 原始位模式。
2. 在 `Emulator` 中增加 `difftestFPR(uint8_t rd, uint32_t rdData, uint32_t pc)`，比较 DUT `wbData` 与 reference `getFprBits(rd)`。
3. 修改 `Emulator` 的提交比对循环：
   - GPR 继续跳过 `x0`。
   - FPR 不跳过 `f0`，因为 FPR 没有硬连零语义。
   - 报错信息区分 `RF mismatch` 和 `FPR mismatch`，并保留 `pc`、寄存器号、DUT/REF 值、pipeline 和 instruction。
4. 第一阶段只比较 FPR 写回结果，不比较 `fflags`。如果后续要完整验证浮点异常状态，需要扩展 debug IO 暴露 `fflags`，并让 reference simulator 维护 `NV/DZ/OF/UF/NX`。

该方案可以覆盖 `FLW`、`FADD.S`、`FSUB.S`、`FMUL.S`、`FDIV.S`、`FSQRT.S`、`FSGNJ*`、`FMIN.S`、`FMAX.S`、`FCVT.S.W`、`FCVT.S.WU`、`FMV.W.X` 和 fused multiply-add 类写 FPR 的指令。写 GPR 的浮点指令，例如 `FEQ.S`、`FLT.S`、`FLE.S`、`FCVT.W.S`、`FMV.X.W` 和 `FCLASS.S`，当前已通过 GPR 路径检查写回值。

直接按 bit 比较的注意事项：

- `memcpy` 本身是安全的取 bit 方式，优于指针强转，也避免 strict-aliasing 问题。
- 真正风险在于当前 reference simulator 使用 C++ host `float` 和 `sqrtf` 直接模拟浮点运算，不是严格的 RISC-V F 扩展 bit-accurate reference。
- NaN payload、canonical NaN、`+0/-0`、subnormal、overflow/underflow、divide-by-zero、invalid operation 等特殊值行为可能与硬件 FPU 不一致。
- 当前 simulator 多数运算没有完整建模 rounding mode，`rm` 和动态舍入模式覆盖不足。
- `FMADD.S`/`FMSUB.S`/`FNMSUB.S`/`FNMADD.S` 在 RISC-V 中需要 fused、一次舍入；当前 C++ 表达式可能产生两次舍入，也可能被 host 编译器融合，行为不适合作为严格 reference。
- 当前 simulator 没有维护 `fflags`，即使结果 bit 一致也不能证明浮点异常状态正确。

因此，FPR bit compare 适合作为第一阶段 difftest 增强，用于暴露普通 f32 路径中的 DUT/REF 写回差异；但如果目标是严格验证浮点执行正确性，应进一步将 reference simulator 改为维护 `uint32_t` FPR 位模式，并引入 SoftFloat 或等价的 RISC-V/IEEE754 reference，实现结果 bit 和 `fflags` 的精确建模。

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

1. 定位 `MatrixFunctions` 中 `matCmplxMult_riscv_mat_cmplx_mult_q15` 的 difftest mismatch。
2. 给 `FilteringFunctions`/`TransformFunctions` 增加更细粒度的 suite 或 case 白名单，避免默认回归时间失控。
3. 修复或确认 legacy 场景下 `lbu` difftest mismatch，再恢复 legacy unsigned logical 组。
4. 确认 f32 指令 difftest 行为，再恢复 legacy f32 BasicMath。
5. 引入最小 libm 或链接可用 libm，启用依赖 math 函数的 f32/f64 测试。
6. 建立 C++ runtime/STL shim 后，再启用 `Testing` C++ 测试系统。
