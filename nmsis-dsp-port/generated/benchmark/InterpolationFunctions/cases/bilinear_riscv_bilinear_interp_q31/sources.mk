TEST_NAME := nmsis-dsp-benchmark-interpolation-bilinear_riscv_bilinear_interp_q31
TEST_SRCS := \
  generated/benchmark/InterpolationFunctions/cases/bilinear_riscv_bilinear_interp_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/InterpolationFunctions/test_riscv_bilinear_interp_q31.c \
  vendor/NMSIS/DSP/Source/InterpolationFunctions/riscv_bilinear_interp_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

