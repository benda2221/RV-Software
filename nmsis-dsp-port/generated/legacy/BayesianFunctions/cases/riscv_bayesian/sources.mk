TEST_NAME := nmsis-dsp-legacy-bayesianfunctions-riscv_bayesian
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/BayesianFunctions/riscv_bayesian.c \
  vendor/NMSIS/DSP/Source/BayesFunctions/riscv_gaussian_naive_bayes_predict_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_max_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

