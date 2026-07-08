TEST_NAME := nmsis-dsp-benchmark-interpolation-linear_riscv_linear_interp_f32
TEST_SRCS := \
  generated/benchmark/InterpolationFunctions/cases/linear_riscv_linear_interp_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_linear_interp_f32.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_linear_interp_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

