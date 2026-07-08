TEST_NAME := nmsis-dsp-benchmark-filtering-correlate_riscv_correlate_q31
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/correlate_riscv_correlate_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_correlate_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_correlate_fast_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

