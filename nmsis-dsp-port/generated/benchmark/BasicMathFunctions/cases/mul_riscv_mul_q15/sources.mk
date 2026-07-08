TEST_NAME := nmsis-dsp-benchmark-basicmath-mul_riscv_mul_q15
TEST_SRCS := \
  generated/benchmark/BasicMathFunctions/cases/mul_riscv_mul_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_mult_q15.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_mult_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

