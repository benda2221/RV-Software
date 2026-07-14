TEST_NAME := nmsis-dsp-legacy-convolutionfunctions-riscv_conv
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/ConvolutionFunctions/riscv_conv.c \
  vendor/NMSIS/DSP/Test/ConvolutionFunctions/ref_riscv_conv.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_fast_opt_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_fast_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_opt_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_opt_q7.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_fast_opt_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_fast_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_opt_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_opt_q7.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_q7.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_q7.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_fast_opt_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_fast_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_opt_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_opt_q7.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_q7.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_fill_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

