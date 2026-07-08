TEST_NAME := nmsis-dsp-benchmark-matrix-matadd_riscv_mat_add_f32
TEST_SRCS := \
  generated/benchmark/MatrixFunctions/cases/matAdd_riscv_mat_add_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/MatrixFunctions/test_riscv_mat_add_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_add_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

