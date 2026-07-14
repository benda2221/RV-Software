TEST_NAME := nmsis-dsp-benchmark-support-q15tof32_riscv_q15_to_f32
TEST_SRCS := \
  generated/benchmark/SupportFunctions/cases/q15ToF32_riscv_q15_to_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

