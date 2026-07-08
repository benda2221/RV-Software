TEST_NAME := nmsis-dsp-benchmark-basicmath-xor_riscv_xor_u16
TEST_SRCS := \
  generated/benchmark/BasicMathFunctions/cases/xor_riscv_xor_u16/runner.c \
  vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_xor_u16.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_xor_u16.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

