TEST_NAME := nmsis-dsp-legacy-convolutionfunctions-ref_riscv_conv
TEST_SRCS := \
  generated/legacy/ConvolutionFunctions/cases/ref_riscv_conv/runner.c \
  vendor/NMSIS/DSP/Test/ConvolutionFunctions/ref_riscv_conv.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

