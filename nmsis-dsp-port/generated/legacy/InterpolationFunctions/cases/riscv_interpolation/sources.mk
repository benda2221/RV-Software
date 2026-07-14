TEST_NAME := nmsis-dsp-legacy-interpolationfunctions-riscv_interpolation
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/InterpolationFunctions/riscv_interpolation.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_f16.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_f32.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_q15.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_q31.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_q7.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_f16.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_f16.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_f32.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_q15.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_q31.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_q7.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q31_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q7_to_float.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

