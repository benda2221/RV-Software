TEST_NAME := nmsis-dsp-benchmark-fastmath-vexp_riscv_vexp_f32
TEST_SRCS := \
  generated/benchmark/FastMathFunctions/cases/vexp_riscv_vexp_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_vexp_f32.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_vexp_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

