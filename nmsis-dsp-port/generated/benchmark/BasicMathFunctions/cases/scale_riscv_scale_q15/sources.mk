TEST_NAME := nmsis-dsp-benchmark-basicmath-scale_riscv_scale_q15
TEST_SRCS := \
  generated/benchmark/BasicMathFunctions/cases/scale_riscv_scale_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_scale_q15.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_scale_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

