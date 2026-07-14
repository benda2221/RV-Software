TEST_NAME := nmsis-dsp-legacy-helperfunctions-math_helper
TEST_SRCS := \
  generated/legacy/HelperFunctions/cases/math_helper/runner.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/math_helper.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

