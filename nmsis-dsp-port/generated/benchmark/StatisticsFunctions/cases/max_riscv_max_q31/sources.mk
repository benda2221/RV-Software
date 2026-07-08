TEST_NAME := nmsis-dsp-benchmark-statistics-max_riscv_max_q31
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/max_riscv_max_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_max_q31.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_max_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

