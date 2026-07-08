TEST_NAME := nmsis-dsp-benchmark-support-copy_riscv_copy_q7
TEST_SRCS := \
  generated/benchmark/SupportFunctions/cases/copy_riscv_copy_q7/runner.c \
  vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_copy_q7.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_q7.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

