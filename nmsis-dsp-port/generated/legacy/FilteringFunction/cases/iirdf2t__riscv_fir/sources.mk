TEST_NAME := nmsis-dsp-legacy-filteringfunction-iirdf2t__riscv_fir
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/FilteringFunction/iirdf2t/riscv_fir.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/iirdf2t/biquad.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df2T_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df2T_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df2T_init_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df2T_init_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_stereo_df2T_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_stereo_df2T_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_stereo_df2T_init_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_stereo_df2T_init_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_f16_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_f16.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

