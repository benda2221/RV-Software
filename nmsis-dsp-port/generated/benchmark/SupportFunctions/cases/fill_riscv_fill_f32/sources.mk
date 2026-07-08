TEST_NAME := nmsis-dsp-benchmark-support-fill_riscv_fill_f32
TEST_SRCS := \
  generated/benchmark/SupportFunctions/cases/fill_riscv_fill_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_fill_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_fill_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

