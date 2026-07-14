TEST_NAME := nmsis-dsp-legacy-helperfunctions-helperfunctions
TEST_SRCS := \
  generated/legacy/HelperFunctions/cases/HelperFunctions/runner.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/HelperFunctions.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

