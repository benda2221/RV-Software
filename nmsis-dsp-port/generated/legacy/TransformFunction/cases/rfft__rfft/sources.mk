TEST_NAME := nmsis-dsp-legacy-transformfunction-rfft__rfft
TEST_SRCS := \
  generated/legacy/TransformFunction/cases/rfft__rfft/runner.c \
  vendor/NMSIS/DSP/Test/TransformFunction/rfft/rfft.c \
  vendor/NMSIS/DSP/Test/TransformFunction/cfft/cfft.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q31_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_f16_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_f16.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

