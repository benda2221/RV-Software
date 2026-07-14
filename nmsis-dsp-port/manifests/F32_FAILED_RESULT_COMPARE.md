# F32 Failed Result Compare

Historical report from before Benchmark f32 was enabled by default. Current generated state is tracked in `manifests/dsp_test_plan.csv` and `manifests/ZIRCON_TEST_PLAN.md`; Benchmark f32 cases now run in simulator-only mode by default and no benchmark f32 case remains skipped.

- Total cases: 44
- Match: 21
- Mismatch: 0
- Failed/incomplete: 23
- CSV: `manifests/f32_failed_result_compare.csv`
- Logs: `/tmp/nmsis-f32-failed-result-compare`

## Mismatches And Failures

| Suite | Function | Status | Sim Result | Host Result | Note |
| --- | --- | --- | --- | --- | --- |
| BayesFunctions | `bayes_riscv_gaussian_naive_bayes_predict_f32` | FAILED | `` | `@@RESULT@@ case=bayes_riscv_gaussian_naive_bayes_predict_f32 hash=0xf040b809` | sim_run_failed |
| ComplexMathFunctions | `cmplx_mag_riscv_cmplx_mag_f32` | FAILED | `` | `@@RESULT@@ case=cmplx_mag_riscv_cmplx_mag_f32 hash=0xc378f98d` | sim_run_failed |
| DistanceFunctions | `correlation_distance_riscv_correlation_distance_f32` | FAILED | `` | `@@RESULT@@ case=correlation_distance_riscv_correlation_distance_f32 hash=0x07dbf889` | sim_run_failed |
| DistanceFunctions | `cosine_distance_riscv_cosine_distance_f32` | FAILED | `` | `@@RESULT@@ case=cosine_distance_riscv_cosine_distance_f32 hash=0x57354741` | sim_run_failed |
| DistanceFunctions | `euclidean_distance_riscv_euclidean_distance_f32` | FAILED | `` | `@@RESULT@@ case=euclidean_distance_riscv_euclidean_distance_f32 hash=0x57354741` | sim_run_failed |
| DistanceFunctions | `jensenshannon_distance_riscv_jensenshannon_distance_f32` | FAILED | `` | `@@RESULT@@ case=jensenshannon_distance_riscv_jensenshannon_distance_f32 hash=0x6ae718b5` | sim_run_failed |
| DistanceFunctions | `minkowski_distance_riscv_minkowski_distance_f32` | FAILED | `` | `@@RESULT@@ case=minkowski_distance_riscv_minkowski_distance_f32 hash=0x6ae718b5` | sim_run_failed |
| FastMathFunctions | `atan2_riscv_atan2_f32` | FAILED | `` | `@@RESULT@@ case=atan2_riscv_atan2_f32 hash=0x29b28c26` | sim_run_failed |
| FastMathFunctions | `sqrt_riscv_sqrt_f32` | FAILED | `` | `@@RESULT@@ case=sqrt_riscv_sqrt_f32 hash=0x994bebc3` | sim_run_failed |
| FastMathFunctions | `vexp_riscv_vexp_f32` | FAILED | `` | `@@RESULT@@ case=vexp_riscv_vexp_f32 hash=0x37e24f1a` | sim_run_failed |
| FastMathFunctions | `vlog_riscv_vlog_f32` | FAILED | `` | `@@RESULT@@ case=vlog_riscv_vlog_f32 hash=0x4d97903e` | sim_run_failed |
| MatrixFunctions | `matCholesky_riscv_mat_cholesky_f32` | FAILED | `` | `@@RESULT@@ case=matCholesky_riscv_mat_cholesky_f32 hash=0x86fde125` | sim_run_failed |
| QuaternionMathFunctions | `quaternionNorm_riscv_quaternion_norm_f32` | FAILED | `` | `@@RESULT@@ case=quaternionNorm_riscv_quaternion_norm_f32 hash=0x689eef6b` | sim_run_failed |
| QuaternionMathFunctions | `quaternionNormalize_riscv_quaternion_normalize_f32` | FAILED | `` | `@@RESULT@@ case=quaternionNormalize_riscv_quaternion_normalize_f32 hash=0x45a6287e` | sim_run_failed |
| QuaternionMathFunctions | `rotation2quaternion_riscv_rotation2quaternion_f32` | FAILED | `` | `@@RESULT@@ case=rotation2quaternion_riscv_rotation2quaternion_f32 hash=0x38fbf301` | sim_run_failed |
| SVMFunctions | `svm_riscv_svm_rbf_predict_f32` | FAILED | `` | `@@RESULT@@ case=svm_riscv_svm_rbf_predict_f32 hash=0x76fd7968` | sim_run_failed |
| SVMFunctions | `svm_riscv_svm_sigmoid_predict_f32` | FAILED | `` | `@@RESULT@@ case=svm_riscv_svm_sigmoid_predict_f32 hash=0x76fd7968` | sim_run_failed |
| StatisticsFunctions | `entropy_riscv_entropy_f32` | FAILED | `` | `@@RESULT@@ case=entropy_riscv_entropy_f32 hash=0x5d04b925` | sim_run_failed |
| StatisticsFunctions | `kullbackLeibler_riscv_kullback_leibler_f32` | FAILED | `` | `@@RESULT@@ case=kullbackLeibler_riscv_kullback_leibler_f32 hash=0x66a8b315` | sim_run_failed |
| StatisticsFunctions | `logsumexpDotProd_riscv_logsumexp_dot_prod_f32` | FAILED | `` | `@@RESULT@@ case=logsumexpDotProd_riscv_logsumexp_dot_prod_f32 hash=0x91a0c530` | sim_run_failed |
| StatisticsFunctions | `logsumexp_riscv_logsumexp_f32` | FAILED | `` | `@@RESULT@@ case=logsumexp_riscv_logsumexp_f32 hash=0xf0a1b9e2` | sim_run_failed |
| StatisticsFunctions | `rms_riscv_rms_f32` | FAILED | `` | `@@RESULT@@ case=rms_riscv_rms_f32 hash=0x6f722896` | sim_run_failed |
| StatisticsFunctions | `std_riscv_std_f32` | FAILED | `` | `@@RESULT@@ case=std_riscv_std_f32 hash=0xeec2e3e3` | sim_run_failed |
