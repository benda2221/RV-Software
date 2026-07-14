TEST_NAME := nmsis-dsp-legacy-filteringfunction-lmspart__lms
TEST_SRCS := \
  generated/legacy/FilteringFunction/cases/LMSPart__lms/runner.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/LMSPart/lms.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

