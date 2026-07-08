TEST_NAME := nmsis-dsp-benchmark-filtering-convpartial_riscv_conv_partial_fast_q31
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/convPartial_riscv_conv_partial_fast_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_conv_partial_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_fast_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_conv_partial_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

