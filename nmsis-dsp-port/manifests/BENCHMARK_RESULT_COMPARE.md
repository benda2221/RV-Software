# Benchmark Result Compare

- Result-bearing cases: 39
- Match: 9
- Mismatch: 30
- Missing result line: 0
- CSV: `manifests/benchmark_result_compare.csv`
- Logs: `build/benchmark-result-compare`

## Non-Matching Or Failed Cases

| Suite | Case | Status | Sim Result | Host Result | Note |
| --- | --- | --- | --- | --- | --- |
| ControllerFunctions | `sin_cos_riscv_sin_cos_q31` | MISMATCH | `@@RESULT@@ case=sin_cos_riscv_sin_cos_q31 hash=0xd7268d8d` | `@@RESULT@@ case=sin_cos_riscv_sin_cos_q31 hash=0xadb79d47` |  |
| FastMathFunctions | `atan2_riscv_atan2_f32` | MISMATCH | `@@RESULT@@ case=atan2_riscv_atan2_f32 hash=0xabab1915` | `@@RESULT@@ case=atan2_riscv_atan2_f32 hash=0x0f539d76` |  |
| FastMathFunctions | `atan2_riscv_atan2_q31` | MISMATCH | `@@RESULT@@ case=atan2_riscv_atan2_q31 hash=0xf41fd3ad` | `@@RESULT@@ case=atan2_riscv_atan2_q31 hash=0x1f1a17bd` |  |
| FastMathFunctions | `divide_riscv_divide_q31` | MISMATCH | `@@RESULT@@ case=divide_riscv_divide_q31 hash=0x4a737b5b` | `@@RESULT@@ case=divide_riscv_divide_q31 hash=0x508edd15` |  |
| FastMathFunctions | `sqrt_riscv_sqrt_f32` | MISMATCH | `@@RESULT@@ case=sqrt_riscv_sqrt_f32 hash=0xd542fd15` | `@@RESULT@@ case=sqrt_riscv_sqrt_f32 hash=0x2740ccec` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_fast_opt_q15` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_opt_q15 hash=0x0b545101` | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_opt_q15 hash=0xea1fb8a2` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_fast_q15` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_q15 hash=0x6c261164` | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_q15 hash=0xc5c9e4c3` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_fast_q31` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_q31 hash=0xdf846467` | `@@RESULT@@ case=convPartial_riscv_conv_partial_fast_q31 hash=0xf6a8256a` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_opt_q15` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_opt_q15 hash=0x18a6139c` | `@@RESULT@@ case=convPartial_riscv_conv_partial_opt_q15 hash=0x41d3e90b` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_opt_q7` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_opt_q7 hash=0xf2c9dcce` | `@@RESULT@@ case=convPartial_riscv_conv_partial_opt_q7 hash=0x1246ac8f` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_q15` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_q15 hash=0x394c340d` | `@@RESULT@@ case=convPartial_riscv_conv_partial_q15 hash=0xf034287e` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_q31` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_q31 hash=0xb3d4151d` | `@@RESULT@@ case=convPartial_riscv_conv_partial_q31 hash=0xe1d69f44` |  |
| FilteringFunctions | `convPartial_riscv_conv_partial_q7` | MISMATCH | `@@RESULT@@ case=convPartial_riscv_conv_partial_q7 hash=0xeed9b52f` | `@@RESULT@@ case=convPartial_riscv_conv_partial_q7 hash=0xdc5ea501` |  |
| FilteringFunctions | `conv_iscv_conv_fast_opt_q15` | MISMATCH | `@@RESULT@@ case=conv_iscv_conv_fast_opt_q15 hash=0x6ce62f71` | `@@RESULT@@ case=conv_iscv_conv_fast_opt_q15 hash=0xde2dd4b1` |  |
| FilteringFunctions | `conv_riscv_conv_fast_q15` | MISMATCH | `@@RESULT@@ case=conv_riscv_conv_fast_q15 hash=0xddcbcba0` | `@@RESULT@@ case=conv_riscv_conv_fast_q15 hash=0x93993987` |  |
| FilteringFunctions | `conv_riscv_conv_fast_q31` | MISMATCH | `@@RESULT@@ case=conv_riscv_conv_fast_q31 hash=0xb0e6eb95` | `@@RESULT@@ case=conv_riscv_conv_fast_q31 hash=0x1fe6b497` |  |
| FilteringFunctions | `conv_riscv_conv_opt_q15` | MISMATCH | `@@RESULT@@ case=conv_riscv_conv_opt_q15 hash=0xead62fa3` | `@@RESULT@@ case=conv_riscv_conv_opt_q15 hash=0xbc82cc64` |  |
| FilteringFunctions | `conv_riscv_conv_opt_q7` | MISMATCH | `@@RESULT@@ case=conv_riscv_conv_opt_q7 hash=0x5c4b99e7` | `@@RESULT@@ case=conv_riscv_conv_opt_q7 hash=0x1dfb870b` |  |
| FilteringFunctions | `conv_riscv_conv_q15` | MISMATCH | `@@RESULT@@ case=conv_riscv_conv_q15 hash=0x81c7e434` | `@@RESULT@@ case=conv_riscv_conv_q15 hash=0xb7961d7a` |  |
| FilteringFunctions | `conv_riscv_conv_q31` | MISMATCH | `@@RESULT@@ case=conv_riscv_conv_q31 hash=0xecd7f2b5` | `@@RESULT@@ case=conv_riscv_conv_q31 hash=0xa4f23d53` |  |
| FilteringFunctions | `conv_riscv_conv_q7` | MISMATCH | `@@RESULT@@ case=conv_riscv_conv_q7 hash=0x4b73ff5f` | `@@RESULT@@ case=conv_riscv_conv_q7 hash=0xc0f8830c` |  |
| FilteringFunctions | `correlate_riscv_correlate_fast_q15` | MISMATCH | `@@RESULT@@ case=correlate_riscv_correlate_fast_q15 hash=0xa563aea3` | `@@RESULT@@ case=correlate_riscv_correlate_fast_q15 hash=0xfca9fd7d` |  |
| FilteringFunctions | `correlate_riscv_correlate_q15` | MISMATCH | `@@RESULT@@ case=correlate_riscv_correlate_q15 hash=0x028f59fc` | `@@RESULT@@ case=correlate_riscv_correlate_q15 hash=0x9444b3a7` |  |
| FilteringFunctions | `firDecimate_riscv_fir_decimate_fast_q15` | MISMATCH | `@@RESULT@@ case=firDecimate_riscv_fir_decimate_fast_q15 hash=0xa220a3b4` | `@@RESULT@@ case=firDecimate_riscv_fir_decimate_fast_q15 hash=0xf20ded27` |  |
| FilteringFunctions | `firDecimate_riscv_fir_decimate_fast_q31` | MISMATCH | `@@RESULT@@ case=firDecimate_riscv_fir_decimate_fast_q31 hash=0x7f3b81fe` | `@@RESULT@@ case=firDecimate_riscv_fir_decimate_fast_q31 hash=0xbacbbb95` |  |
| FilteringFunctions | `firDecimate_riscv_fir_decimate_q15` | MISMATCH | `@@RESULT@@ case=firDecimate_riscv_fir_decimate_q15 hash=0xc405ed95` | `@@RESULT@@ case=firDecimate_riscv_fir_decimate_q15 hash=0x154c8ddc` |  |
| FilteringFunctions | `firDecimate_riscv_fir_decimate_q31` | MISMATCH | `@@RESULT@@ case=firDecimate_riscv_fir_decimate_q31 hash=0x8dd6f24f` | `@@RESULT@@ case=firDecimate_riscv_fir_decimate_q31 hash=0xfdadf6cd` |  |
| FilteringFunctions | `firLattice_riscv_fir_lattice_q15` | MISMATCH | `@@RESULT@@ case=firLattice_riscv_fir_lattice_q15 hash=0x08ec3db0` | `@@RESULT@@ case=firLattice_riscv_fir_lattice_q15 hash=0xe3dd62d1` |  |
| FilteringFunctions | `firLattice_riscv_fir_lattice_q31` | MISMATCH | `@@RESULT@@ case=firLattice_riscv_fir_lattice_q31 hash=0x1dcc3912` | `@@RESULT@@ case=firLattice_riscv_fir_lattice_q31 hash=0x2198012c` |  |
| MatrixFunctions | `matMult_riscv_mat_mult_q15` | MISMATCH | `@@RESULT@@ case=matMult_riscv_mat_mult_q15 hash=0xb1d7e666` | `@@RESULT@@ case=matMult_riscv_mat_mult_q15 hash=0xfd83ced9` |  |
