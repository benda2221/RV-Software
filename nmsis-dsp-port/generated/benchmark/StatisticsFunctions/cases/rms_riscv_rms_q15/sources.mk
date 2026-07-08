TEST_NAME := nmsis-dsp-benchmark-statistics-rms_riscv_rms_q15
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/rms_riscv_rms_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_rms_q15.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_rms_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

