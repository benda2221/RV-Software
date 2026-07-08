TEST_NAME := nmsis-dsp-benchmark-interpolation-bilinear_riscv_bilinear_interp_q15
TEST_SRCS := \
  generated/benchmark/InterpolationFunctions/cases/bilinear_riscv_bilinear_interp_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_bilinear_interp_q15.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_q15.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

