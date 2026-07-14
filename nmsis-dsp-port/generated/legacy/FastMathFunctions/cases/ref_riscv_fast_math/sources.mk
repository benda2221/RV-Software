TEST_NAME := nmsis-dsp-legacy-fastmathfunctions-ref_riscv_fast_math
TEST_SRCS := \
  generated/legacy/FastMathFunctions/cases/ref_riscv_fast_math/runner.c \
  vendor/NMSIS/DSP/Test/FastMathFunctions/ref_riscv_fast_math.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

