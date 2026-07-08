TEST_NAME := nmsis-dsp-benchmark-filtering-conv_riscv_conv_fast_q31
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/conv_riscv_conv_fast_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_conv_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

