# Benchmark Result Compare

- Result-bearing cases: 101
- Match: 99
- Mismatch: 2
- Missing result line: 0
- CSV: `manifests/benchmark_result_compare.csv`
- Logs: `build/benchmark-result-compare`

## Non-Matching Or Failed Cases

| Suite | Case | Status | Sim Result | Host Result | Note |
| --- | --- | --- | --- | --- | --- |
| ComplexMathFunctions | `cmplx_mag_riscv_cmplx_mag_f32` | MISMATCH | `@@RESULT@@ case=cmplx_mag_riscv_cmplx_mag_f32 hash=0xd5bdedbc` | `@@RESULT@@ case=cmplx_mag_riscv_cmplx_mag_f32 hash=0xc378f98d` |  |
| ControllerFunctions | `sin_cos_riscv_sin_cos_q31` | MISMATCH | `@@RESULT@@ case=sin_cos_riscv_sin_cos_q31 hash=0xd7268d8d` | `@@RESULT@@ case=sin_cos_riscv_sin_cos_q31 hash=0xadb79d47` |  |
