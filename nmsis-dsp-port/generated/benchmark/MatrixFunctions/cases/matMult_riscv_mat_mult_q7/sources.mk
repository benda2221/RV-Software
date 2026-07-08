TEST_NAME := nmsis-dsp-benchmark-matrix-matmult_riscv_mat_mult_q7
TEST_SRCS := \
  generated/benchmark/MatrixFunctions/cases/matMult_riscv_mat_mult_q7/runner.c \
  vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_mult_q7.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_q7.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_q7.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_trans_q7.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

