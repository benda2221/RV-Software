TEST_NAME := nmsis-dsp-benchmark-statistics-absminnoidx_riscv_absmin_no_idx_q7
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/absminNoIdx_riscv_absmin_no_idx_q7/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_absmin_no_idx_q7.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_absmin_no_idx_q7.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

