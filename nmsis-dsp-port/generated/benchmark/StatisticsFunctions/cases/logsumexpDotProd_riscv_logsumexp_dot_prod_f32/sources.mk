TEST_NAME := nmsis-dsp-benchmark-statistics-logsumexpdotprod_riscv_logsumexp_dot_prod_f32
TEST_SRCS := \
  generated/benchmark/StatisticsFunctions/cases/logsumexpDotProd_riscv_logsumexp_dot_prod_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/StatisticsFunctions/test_riscv_logsumexp_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_logsumexp_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_add_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_logsumexp_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

