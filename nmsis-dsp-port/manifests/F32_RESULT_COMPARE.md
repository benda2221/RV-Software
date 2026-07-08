# F32 Result Compare

- Total cases: 65
- Match: 64
- Mismatch: 1
- Failed/incomplete: 0
- CSV: `manifests/f32_result_compare.csv`
- Logs: `/tmp/nmsis-f32-result-compare`

## Mismatches And Failures

| Suite | Function | Status | Sim Result | Host Result | Note |
| --- | --- | --- | --- | --- | --- |
| FilteringFunctions | `firLattice_riscv_fir_lattice_f32` | MISMATCH | `@@RESULT@@ case=firLattice_riscv_fir_lattice_f32 hash=0xcc562f5c` | `@@RESULT@@ case=firLattice_riscv_fir_lattice_f32 hash=0x16772166` |  |
