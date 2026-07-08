TEST_NAME := nmsis-dsp-benchmark-fastmath-cos_riscv_cos_q15
TEST_SRCS := \
  generated/benchmark/FastMathFunctions/cases/cos_riscv_cos_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_cos_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_cos_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

