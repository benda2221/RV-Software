TEST_NAME := nmsis-dsp-legacy-complexmathfunctions-riscv_cmplx_math
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/ComplexMathFunctions/riscv_cmplx_math.c \
  vendor/NMSIS/DSP/Test/ComplexMathFunctions/ref_riscv_cmplx_math.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_conj_f32.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_conj_q15.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_conj_q31.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_dot_prod_q15.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_dot_prod_q31.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mag_f32.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mag_q15.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mag_q31.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mag_squared_f32.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mag_squared_q15.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mag_squared_q31.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mult_cmplx_f32.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mult_cmplx_q15.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mult_cmplx_q31.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mult_real_f32.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mult_real_q15.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mult_real_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

