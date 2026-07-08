TEST_NAME := nmsis-dsp-benchmark-interpolation
TEST_SRCS := \
  generated/benchmark/InterpolationFunctions/runner.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_bilinear_interp_f32.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_bilinear_interp_q15.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_bilinear_interp_q31.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_bilinear_interp_q7.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_linear_interp_q15.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_linear_interp_q31.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_linear_interp_q7.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_spline_f32.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_f32.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_q15.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_q31.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_q7.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_q15.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_q31.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_q7.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_spline_interp_f32.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_spline_interp_init_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

