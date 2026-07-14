TEST_NAME := nmsis-dsp-benchmark-fastmath-atan2_riscv_atan2_f32
TEST_SRCS := \
  generated/benchmark/FastMathFunctions/cases/atan2_riscv_atan2_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_atan2_f32.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_atan2_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

