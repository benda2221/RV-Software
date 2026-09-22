# Benchmark Result Compare

- Result-bearing cases: 323
- Match: 293
- Mismatch: 12
- Missing result line: 18
- CSV: `manifests/benchmark_result_compare.csv`
- Logs: `build/benchmark-result-compare`

## Non-Matching Or Failed Cases

| Suite | Case | Status | Sim Result | Host Result | Note |
| --- | --- | --- | --- | --- | --- |
| ControllerFunctions | `<suite>` | HOST_COMPILE_FAILED | `` | `` | host_compile_rc=1 |
| FastMathFunctions | `<suite>` | SIM_FAILED | `` | `` | sim_rc=2 |
| FastMathFunctions | `atan2_riscv_atan2_f32` | MISSING_RESULT | `` | `@@RESULT@@ case=atan2_riscv_atan2_f32 hash=0x0f539d76` |  |
| FastMathFunctions | `atan2_riscv_atan2_q15` | MISSING_RESULT | `` | `@@RESULT@@ case=atan2_riscv_atan2_q15 hash=0xd4d05415` |  |
| FastMathFunctions | `atan2_riscv_atan2_q31` | MISSING_RESULT | `` | `@@RESULT@@ case=atan2_riscv_atan2_q31 hash=0x1f1a17bd` |  |
| FastMathFunctions | `cos_riscv_cos_f32` | MISSING_RESULT | `` | `@@RESULT@@ case=cos_riscv_cos_f32 hash=0x153ba769` |  |
| FastMathFunctions | `cos_riscv_cos_q15` | MISSING_RESULT | `` | `@@RESULT@@ case=cos_riscv_cos_q15 hash=0xe4f163e6` |  |
| FastMathFunctions | `cos_riscv_cos_q31` | MISSING_RESULT | `` | `@@RESULT@@ case=cos_riscv_cos_q31 hash=0x1dc18da4` |  |
| FastMathFunctions | `divide_riscv_divide_q15` | MISSING_RESULT | `` | `@@RESULT@@ case=divide_riscv_divide_q15 hash=0x87546915` |  |
| FastMathFunctions | `divide_riscv_divide_q31` | MISSING_RESULT | `` | `@@RESULT@@ case=divide_riscv_divide_q31 hash=0x508edd15` |  |
| FastMathFunctions | `sin_riscv_sin_f32` | MISSING_RESULT | `` | `@@RESULT@@ case=sin_riscv_sin_f32 hash=0x08b5b827` |  |
| FastMathFunctions | `sin_riscv_sin_q15` | MISSING_RESULT | `` | `@@RESULT@@ case=sin_riscv_sin_q15 hash=0xf66ff90c` |  |
| FastMathFunctions | `sin_riscv_sin_q31` | MISSING_RESULT | `` | `@@RESULT@@ case=sin_riscv_sin_q31 hash=0x8feee85d` |  |
| FastMathFunctions | `sqrt_riscv_sqrt_f32` | MISSING_RESULT | `` | `@@RESULT@@ case=sqrt_riscv_sqrt_f32 hash=0x2740ccec` |  |
| FastMathFunctions | `sqrt_riscv_sqrt_q15` | MISSING_RESULT | `` | `@@RESULT@@ case=sqrt_riscv_sqrt_q15 hash=0xa2c6f572` |  |
| FastMathFunctions | `sqrt_riscv_sqrt_q31` | MISSING_RESULT | `` | `@@RESULT@@ case=sqrt_riscv_sqrt_q31 hash=0xc0ed3ec8` |  |
| FastMathFunctions | `vexp_riscv_vexp_f32` | MISSING_RESULT | `` | `@@RESULT@@ case=vexp_riscv_vexp_f32 hash=0x25af2633` |  |
| FastMathFunctions | `vlog_riscv_vlog_f32` | MISSING_RESULT | `` | `@@RESULT@@ case=vlog_riscv_vlog_f32 hash=0x18d21d9b` |  |
| FastMathFunctions | `vlog_riscv_vlog_q15` | MISSING_RESULT | `` | `@@RESULT@@ case=vlog_riscv_vlog_q15 hash=0xb8cbe350` |  |
| FastMathFunctions | `vlog_riscv_vlog_q31` | MISSING_RESULT | `` | `@@RESULT@@ case=vlog_riscv_vlog_q31 hash=0x95c43d01` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_fast_opt_q15` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_opt_q15 hash=0xa3bbe1f0` | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_opt_q15 hash=0x02ebed77` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_fast_q15` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_q15 hash=0x69b5d6ef` | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_q15 hash=0x9cba0bcd` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_opt_q15` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_opt_q15 hash=0xc8a5c52e` | `@@RESULT@@ case=convPartial_riscv_conv_partial_opt_q15 hash=0x68504db9` |  |
| FilteringFunctions | `conv_riscv_conv_fast_q15` | MISMATCH | `@@RESULT@@ case=conv_riscv_conv_fast_q15 hash=0x1932a6f1` | `@@RESULT@@ case=conv_riscv_conv_fast_q15 hash=0x3a92e33f` |  |
| FilteringFunctions | `correlate_riscv_correlate_fast_q15` | MISMATCH | `@@RESULT@@ case=correlate_riscv_correlate_fast_q15 hash=0x5b81f72b` | `@@RESULT@@ case=correlate_riscv_correlate_fast_q15 hash=0xa733800f` |  |
| FilteringFunctions | `lms_riscv_lms_f32` | MISMATCH | `@@RESULT@@ case=lms_riscv_lms_f32 hash=0x22050801` | `@@RESULT@@ case=lms_riscv_lms_f32 hash=0xdc1d1401` |  |
| StatisticsFunctions | `rms_riscv_rms_q15` | MISMATCH | `@@RESULT@@ case=rms_riscv_rms_q15 hash=0x40901c82` | `@@RESULT@@ case=rms_riscv_rms_q15 hash=0x60800e86` |  |
| StatisticsFunctions | `rms_riscv_rms_q31` | MISMATCH | `@@RESULT@@ case=rms_riscv_rms_q31 hash=0x4b95f515` | `@@RESULT@@ case=rms_riscv_rms_q31 hash=0xe7b6a26c` |  |
| StatisticsFunctions | `std_riscv_std_q15` | MISMATCH | `@@RESULT@@ case=std_riscv_std_q15 hash=0x117697cd` | `@@RESULT@@ case=std_riscv_std_q15 hash=0x60800e86` |  |
| StatisticsFunctions | `std_riscv_std_q31` | MISMATCH | `@@RESULT@@ case=std_riscv_std_q31 hash=0x50c0f694` | `@@RESULT@@ case=std_riscv_std_q31 hash=0xace8dfdf` |  |
| StatisticsFunctions | `var_riscv_var_q15` | MISMATCH | `@@RESULT@@ case=var_riscv_var_q15 hash=0x117697cd` | `@@RESULT@@ case=var_riscv_var_q15 hash=0xa7953bd5` |  |
| StatisticsFunctions | `var_riscv_var_q31` | MISMATCH | `@@RESULT@@ case=var_riscv_var_q31 hash=0x9793d0f4` | `@@RESULT@@ case=var_riscv_var_q31 hash=0x85548392` |  |
