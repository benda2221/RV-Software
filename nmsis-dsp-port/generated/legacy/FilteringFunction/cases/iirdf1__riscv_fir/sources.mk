TEST_NAME := nmsis-dsp-legacy-filteringfunction-iirdf1__riscv_fir
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/FilteringFunction/iirdf1/riscv_fir.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/iirdf1/biquad.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_32x64_init_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_32x64_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_fast_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_init_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_init_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_init_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_init_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df1_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_f16_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_f16.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q31_to_float.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

