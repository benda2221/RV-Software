TEST_NAME := nmsis-dsp-benchmark-basicmath-not_riscv_not_u8
TEST_SRCS := \
  generated/benchmark/BasicMathFunctions/cases/not_riscv_not_u8/runner.c \
  vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_not_u8.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_not_u8.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

