TEST_NAME := nmsis-dsp-legacy-filteringfunction-firpart__fir
TEST_SRCS := \
  generated/legacy/FilteringFunction/cases/firPart__fir/runner.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/firPart/fir.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

