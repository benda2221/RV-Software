TEST_NAME := nmsis-dsp-legacy-filteringfunction-firinterpolatepart__riscv_fir
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/FilteringFunction/firInterpolatePart/riscv_fir.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/firInterpolatePart/fir_interpolate.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_interpolate_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_interpolate_init_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_interpolate_init_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_interpolate_init_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_interpolate_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_interpolate_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q31_to_float.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/math_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

