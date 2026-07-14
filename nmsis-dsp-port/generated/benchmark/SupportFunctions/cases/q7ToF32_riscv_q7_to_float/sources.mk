TEST_NAME := nmsis-dsp-benchmark-support-q7tof32_riscv_q7_to_float
TEST_SRCS := \
  generated/benchmark/SupportFunctions/cases/q7ToF32_riscv_q7_to_float/runner.c \
  vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_q7_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q7_to_float.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

