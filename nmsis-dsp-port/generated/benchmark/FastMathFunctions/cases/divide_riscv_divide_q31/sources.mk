TEST_NAME := nmsis-dsp-benchmark-fastmath-divide_riscv_divide_q31
TEST_SRCS := \
  generated/benchmark/FastMathFunctions/cases/divide_riscv_divide_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_divide_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_divide_q31.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_abs_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

