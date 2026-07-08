TEST_NAME := nmsis-dsp-benchmark-filtering-firinterpolate_riscv_fir_interpolate_q15
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/firInterpolate_riscv_fir_interpolate_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_interpolate_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_interpolate_init_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_interpolate_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

