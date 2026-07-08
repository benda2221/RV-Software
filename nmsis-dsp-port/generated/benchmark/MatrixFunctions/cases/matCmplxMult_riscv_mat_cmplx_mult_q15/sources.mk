TEST_NAME := nmsis-dsp-benchmark-matrix-matcmplxmult_riscv_mat_cmplx_mult_q15
TEST_SRCS := \
  generated/benchmark/MatrixFunctions/cases/matCmplxMult_riscv_mat_cmplx_mult_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_cmplx_mult_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_cmplx_mult_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

