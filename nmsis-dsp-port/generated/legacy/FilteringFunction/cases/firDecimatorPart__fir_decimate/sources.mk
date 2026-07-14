TEST_NAME := nmsis-dsp-legacy-filteringfunction-firdecimatorpart__fir_decimate
TEST_SRCS := \
  generated/legacy/FilteringFunction/cases/firDecimatorPart__fir_decimate/runner.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/firDecimatorPart/fir_decimate.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

