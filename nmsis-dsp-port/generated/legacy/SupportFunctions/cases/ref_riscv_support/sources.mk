TEST_NAME := nmsis-dsp-legacy-supportfunctions-ref_riscv_support
TEST_SRCS := \
  generated/legacy/SupportFunctions/cases/ref_riscv_support/runner.c \
  vendor/NMSIS/DSP/Test/SupportFunctions/ref_riscv_support.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

