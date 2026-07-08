TEST_NAME := nmsis-dsp-benchmark-statistics-min_riscv_min_q15
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/min_riscv_min_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_min_q15.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_min_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

