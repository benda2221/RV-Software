TEST_NAME := nmsis-dsp-benchmark-basicmath-dot_prod_riscv_dot_prod_f32
TEST_SRCS := \
  generated/benchmark/BasicMathFunctions/cases/dot_prod_riscv_dot_prod_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

