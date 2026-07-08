TEST_NAME := nmsis-dsp-benchmark-basicmath-sub_riscv_sub_q31
TEST_SRCS := \
  generated/benchmark/BasicMathFunctions/cases/sub_riscv_sub_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_sub_q31.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_sub_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

