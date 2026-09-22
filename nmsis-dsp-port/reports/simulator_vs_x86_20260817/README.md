# NMSIS-DSP 纯 Simulator 与 x86 结果比较

日期：2026-08-17

## 测试范围与配置

本次运行 `generated/benchmark` 下的 14 个 suite、337 个生成 case。目标端只使用
Zircon reference Simulator，不启动 RTL/difftest：

```bash
cd /home/zhangfulin/RISCV-VLIW/Zircon-VLIW/RV-Software/nmsis-dsp-port
python3 scripts/compare_benchmark_results.py
```

比较脚本对 Benchmark 输出数组和结果变量计算确定性的结果哈希，并比较目标端与 x86
host 的结果行。构建配置为：

- 目标前端：`-mcpu=dandelion -march=rv32imf`
- 目标 LLC：`-mcpu=dandelion -mattr=+m,+f,-d,-unaligned-scalar-mem`
- 运行模式：`USE_SIMULATOR_ONLY_MODE=1`
- x86：`gcc -std=gnu99 -O2 -fno-builtin ... -lm`

FastMath 聚合目标和 Controller host 聚合目标发生构建失败后，又逐 case 运行这两个
suite，避免单个 case 的构建错误遮蔽同 suite 的其他结果。本报告采用逐 case 补测后的
校正统计；脚本直接生成的原始聚合报告仍保存在
`manifests/BENCHMARK_RESULT_COMPARE.md`。

## 总体结果

| 结果 | case 数量 |
| --- | ---: |
| Simulator 与 x86 一致 | 294 |
| Simulator 与 x86 结果哈希不一致 | 41 |
| 无法形成双侧结果 | 2 |
| 合计 | 337 |

在实际得到双侧结果的 335 个 case 中，294 个一致，41 个不一致，一致率为
`294 / 335 = 87.76%`。

| Suite | 一致 | 不一致 | 无法比较 | 合计 |
| --- | ---: | ---: | ---: | ---: |
| BasicMathFunctions | 51 | 0 | 0 | 51 |
| BayesFunctions | 1 | 0 | 0 | 1 |
| ComplexMathFunctions | 19 | 0 | 0 | 19 |
| ControllerFunctions | 11 | 1 | 1 | 13 |
| DistanceFunctions | 18 | 0 | 0 | 18 |
| FastMathFunctions | 15 | 2 | 1 | 18 |
| FilteringFunctions | 36 | 31 | 0 | 67 |
| InterpolationFunctions | 9 | 0 | 0 | 9 |
| MatrixFunctions | 31 | 1 | 0 | 32 |
| QuaternionMathFunctions | 8 | 0 | 0 | 8 |
| SVMFunctions | 4 | 0 | 0 | 4 |
| StatisticsFunctions | 51 | 6 | 0 | 57 |
| SupportFunctions | 24 | 0 | 0 | 24 |
| TransformFunctions | 16 | 0 | 0 | 16 |
| **合计** | **294** | **41** | **2** | **337** |

## 结果不一致 case（41 个）

### ControllerFunctions（1）

- `sin_cos_riscv_sin_cos_q31`
  - Simulator：`0xd7268d8d`
  - x86：`0xadb79d47`

### FastMathFunctions（2）

- `atan2_riscv_atan2_q31`
  - Simulator：`0xf41fd3ad`
  - x86：`0x1f1a17bd`
- `divide_riscv_divide_q31`
  - Simulator：`0x4a737b5b`
  - x86：`0x508edd15`

### FilteringFunctions（31）

`convPartial`：

- `convPartial_riscv_conv_partial_fast_opt_q15`
- `convPartial_riscv_conv_partial_fast_q15`
- `convPartial_riscv_conv_partial_fast_q31`
- `convPartial_riscv_conv_partial_opt_q15`
- `convPartial_riscv_conv_partial_opt_q7`
- `convPartial_riscv_conv_partial_q15`
- `convPartial_riscv_conv_partial_q31`
- `convPartial_riscv_conv_partial_q7`

`conv`：

- `conv_iscv_conv_fast_opt_q15`
- `conv_riscv_conv_fast_q15`
- `conv_riscv_conv_fast_q31`
- `conv_riscv_conv_opt_q15`
- `conv_riscv_conv_opt_q7`
- `conv_riscv_conv_q15`
- `conv_riscv_conv_q31`
- `conv_riscv_conv_q7`

`correlate`：

- `correlate_riscv_correlate_fast_opt_q15`
- `correlate_riscv_correlate_fast_q15`
- `correlate_riscv_correlate_fast_q31`
- `correlate_riscv_correlate_opt_q15`
- `correlate_riscv_correlate_opt_q7`
- `correlate_riscv_correlate_q15`
- `correlate_riscv_correlate_q31`
- `correlate_riscv_correlate_q7`

其他 Filtering case：

- `firDecimate_riscv_fir_decimate_fast_q15`
- `firDecimate_riscv_fir_decimate_fast_q31`
- `firDecimate_riscv_fir_decimate_q15`
- `firDecimate_riscv_fir_decimate_q31`
- `firLattice_riscv_fir_lattice_q15`
- `firLattice_riscv_fir_lattice_q31`
- `lms_riscv_lms_f32`

### MatrixFunctions（1）

- `matMult_riscv_mat_mult_q15`

### StatisticsFunctions（6）

- `rms_riscv_rms_q15`
- `rms_riscv_rms_q31`
- `std_riscv_std_q15`
- `std_riscv_std_q31`
- `var_riscv_var_q15`
- `var_riscv_var_q31`

上述 Filtering、Matrix 和 Statistics case 的两侧完整哈希记录位于
`manifests/BENCHMARK_RESULT_COMPARE.md` 和
`manifests/benchmark_result_compare.csv`。

## 无法比较 case（2 个）

### `FastMathFunctions/sqrt_riscv_sqrt_f32`

x86 运行成功，但 RV32IMF 目标在链接阶段失败，没有进入 Simulator。测试源码中的
表达式使用了 `1.0`（double）而不是 `1.0f`，目标链接缺少：

```text
__floatsidf
__divdf3
__truncdfsf2
```

日志：
`build/benchmark-result-compare/sim/FastMathFunctions.sqrt_riscv_sqrt_f32.log`

### `ControllerFunctions/pid_riscv_pid_q15`

目标纯 Simulator 运行成功并得到：

```text
@@RESULT@@ case=pid_riscv_pid_q15 hash=0x1443862d
```

但 x86 GCC 在汇编阶段遇到移植头文件中的 RISC-V 指令，无法生成 host 结果：

```text
Error: no such instruction: `feq.s zero,ft0,ft0'
```

日志：
`build/benchmark-result-compare/host/pid_riscv_pid_q15.compile.log`

## 比较脚本漏计项

`StatisticsFunctions/absmin_riscv_absmin_f32` 的结果行使用 `value_bits`，没有使用脚本
正则要求的 `hash` 或 `checksum` 字段，因此没有进入自动 CSV 计数。人工比较原始日志后，
两侧结果完全相同，已计入本报告的“一致”数量：

```text
@@RESULT@@ case=riscv_absmin_f32 count=256 index=0 value_bits=0x39040420
```

## 与非对齐 `SW` 问题的关系

`FilteringFunctions/conv_riscv_conv_fast_q15` 在纯 Simulator 与 x86 间仍然不一致。
该 case 已确认会对 `4n+2` 地址执行 `sw`。x86 能执行非对齐写，而当前 reference
Simulator 的写掩码逻辑不能完整模拟跨 word 的非对齐 32 位访问，因此纯 Simulator
结果也不能与 x86 等价。根因记录见：
`reports/strict_alignment_20260817/FILTERING_CONV_FAST_Q15_UNALIGNED_SW.md`。

41 个不一致 case 的后续逐项归因已经完成。它们可分为未初始化区域被纳入哈希、严格
对齐访问契约、Benchmark 数组越界、RV32 软件 64 位除法错误、C 未定义行为和 NaN 位
模式差异六类，详见 [ROOT_CAUSE_ANALYSIS.md](ROOT_CAUSE_ANALYSIS.md)。不能据此认为它们
全部来自相同的非对齐访问问题。

## 本次修改范围

本次仅新增问题记录和测试结果报告，没有修改 NMSIS 算法、移植层、LLVM、RTL 或
Simulator 实现。
