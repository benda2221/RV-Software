TEST_NAME := nmsis-dsp-legacy-filteringfunction-iirdf1__biquad
TEST_SRCS := \
  generated/legacy/FilteringFunction/cases/iirdf1__biquad/runner.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/iirdf1/biquad.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

