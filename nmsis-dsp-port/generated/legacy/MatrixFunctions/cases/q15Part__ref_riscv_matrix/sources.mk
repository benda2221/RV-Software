TEST_NAME := nmsis-dsp-legacy-matrixfunctions-q15part__ref_riscv_matrix
TEST_SRCS := \
  generated/legacy/MatrixFunctions/cases/q15Part__ref_riscv_matrix/runner.c \
  vendor/NMSIS/DSP/Test/MatrixFunctions/q15Part/ref_riscv_matrix.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

