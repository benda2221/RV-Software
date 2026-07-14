TEST_NAME := nmsis-dsp-legacy-transformfunction-dct4__dct4
TEST_SRCS := \
  generated/legacy/TransformFunction/cases/dct4__dct4/runner.c \
  vendor/NMSIS/DSP/Test/TransformFunction/dct4/dct4.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q31_to_float.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

