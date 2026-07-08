TEST_NAME := nmsis-dsp-benchmark-statistics-absmin_riscv_absmin_q7
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/absmin_riscv_absmin_q7/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_absmin_q7.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_absmin_q7.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

