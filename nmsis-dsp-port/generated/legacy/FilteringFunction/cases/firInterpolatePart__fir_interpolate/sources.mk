TEST_NAME := nmsis-dsp-legacy-filteringfunction-firinterpolatepart__fir_interpolate
TEST_SRCS := \
  generated/legacy/FilteringFunction/cases/firInterpolatePart__fir_interpolate/runner.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/firInterpolatePart/fir_interpolate.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

