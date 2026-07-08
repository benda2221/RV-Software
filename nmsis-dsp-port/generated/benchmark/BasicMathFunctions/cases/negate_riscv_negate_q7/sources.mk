TEST_NAME := nmsis-dsp-benchmark-basicmath-negate_riscv_negate_q7
TEST_SRCS := \
  generated/benchmark/BasicMathFunctions/cases/negate_riscv_negate_q7/runner.c \
  vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_negate_q7.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_negate_q7.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

