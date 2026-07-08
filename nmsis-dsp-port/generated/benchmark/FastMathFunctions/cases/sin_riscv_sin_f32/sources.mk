TEST_NAME := nmsis-dsp-benchmark-fastmath-sin_riscv_sin_f32
TEST_SRCS := \
  generated/benchmark/FastMathFunctions/cases/sin_riscv_sin_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_sin_f32.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sin_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

