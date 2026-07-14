TEST_NAME := nmsis-dsp-legacy-complexmathfunctions-ref_riscv_cmplx_math
TEST_SRCS := \
  generated/legacy/ComplexMathFunctions/cases/ref_riscv_cmplx_math/runner.c \
  vendor/NMSIS/DSP/Test/ComplexMathFunctions/ref_riscv_cmplx_math.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

