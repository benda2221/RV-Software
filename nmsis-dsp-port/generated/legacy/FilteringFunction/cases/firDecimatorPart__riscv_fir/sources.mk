TEST_NAME := nmsis-dsp-legacy-filteringfunction-firdecimatorpart__riscv_fir
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/FilteringFunction/firDecimatorPart/riscv_fir.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/firDecimatorPart/fir_decimate.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_fast_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_init_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_init_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_init_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q31_to_float.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

