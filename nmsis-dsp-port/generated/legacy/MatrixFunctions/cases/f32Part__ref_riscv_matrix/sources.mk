TEST_NAME := nmsis-dsp-legacy-matrixfunctions-f32part__ref_riscv_matrix
TEST_SRCS := \
  generated/legacy/MatrixFunctions/cases/f32Part__ref_riscv_matrix/runner.c \
  vendor/NMSIS/DSP/Test/MatrixFunctions/f32Part/ref_riscv_matrix.c \
  port/src/ref_matrix_f32_subset.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

