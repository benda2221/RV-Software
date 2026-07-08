TEST_NAME := nmsis-dsp-benchmark-fastmath-atan2_riscv_atan2_q31
TEST_SRCS := \
  generated/benchmark/FastMathFunctions/cases/atan2_riscv_atan2_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_atan2_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_atan2_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_divide_q31.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_abs_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_cos_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

