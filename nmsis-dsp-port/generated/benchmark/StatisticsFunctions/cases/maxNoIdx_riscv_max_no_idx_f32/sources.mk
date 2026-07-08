TEST_NAME := nmsis-dsp-benchmark-statistics-maxnoidx_riscv_max_no_idx_f32
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/maxNoIdx_riscv_max_no_idx_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_max_no_idx_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_max_no_idx_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

