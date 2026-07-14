TEST_NAME := nmsis-dsp-benchmark-bayes-bayes_riscv_gaussian_naive_bayes_predict_f32
TEST_SRCS := \
  generated/benchmark/BayesFunctions/cases/bayes_riscv_gaussian_naive_bayes_predict_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/BayesFunctions/test_riscv_gaussian_naive_bayes_predict_f32.c \
  vendor/NMSIS/DSP/Source/BayesFunctions/riscv_gaussian_naive_bayes_predict_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_max_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

