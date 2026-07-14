TEST_NAME := nmsis-dsp-legacy-fastmathfunctions-riscv_fast_math
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/FastMathFunctions/riscv_fast_math.c \
  vendor/NMSIS/DSP/Test/FastMathFunctions/ref_riscv_fast_math.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_cos_f32.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_cos_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_cos_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_divide_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sin_f32.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sin_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sin_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_vexp_f16.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_vexp_f32.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_vlog_f16.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_vlog_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_abs_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

