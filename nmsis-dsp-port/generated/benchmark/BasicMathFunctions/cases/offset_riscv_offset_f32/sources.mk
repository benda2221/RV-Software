TEST_NAME := nmsis-dsp-benchmark-basicmath-offset_riscv_offset_f32
TEST_SRCS := \
  generated/benchmark/BasicMathFunctions/cases/offset_riscv_offset_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/BasicMathFunctions/test_riscv_offset_f32.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_offset_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

