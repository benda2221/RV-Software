TEST_NAME := nmsis-dsp-benchmark-statistics-mean_riscv_mean_q31
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/mean_riscv_mean_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_mean_q31.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_mean_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

