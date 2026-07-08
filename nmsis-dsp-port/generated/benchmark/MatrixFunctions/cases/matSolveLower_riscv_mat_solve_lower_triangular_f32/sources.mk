TEST_NAME := nmsis-dsp-benchmark-matrix-matsolvelower_riscv_mat_solve_lower_triangular_f32
TEST_SRCS := \
  generated/benchmark/MatrixFunctions/cases/matSolveLower_riscv_mat_solve_lower_triangular_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_solve_lower_triangular_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_solve_lower_triangular_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

