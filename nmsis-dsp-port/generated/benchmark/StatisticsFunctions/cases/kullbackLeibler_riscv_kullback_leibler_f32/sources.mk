TEST_NAME := nmsis-dsp-benchmark-statistics-kullbackleibler_riscv_kullback_leibler_f32
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/kullbackLeibler_riscv_kullback_leibler_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_kullback_leibler_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_kullback_leibler_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

