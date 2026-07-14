TEST_NAME := nmsis-dsp-legacy-basicmathfunctions-ref_basic_math_functions
TEST_SRCS := \
  generated/legacy/BasicMathFunctions/cases/ref_basic_math_functions/runner.c \
  vendor/NMSIS/DSP/Test/BasicMathFunctions/ref_basic_math_functions.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

