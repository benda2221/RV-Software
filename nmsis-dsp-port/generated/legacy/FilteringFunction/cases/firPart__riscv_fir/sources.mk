TEST_NAME := nmsis-dsp-legacy-filteringfunction-firpart__riscv_fir
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/FilteringFunction/firPart/riscv_fir.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/firPart/fir.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_f16_to_float.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_fast_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_init_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_init_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_init_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_init_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_init_q7.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_q7.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_f16.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q7.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q31_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q7_to_float.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/math_helper.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_f16.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_q7.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

