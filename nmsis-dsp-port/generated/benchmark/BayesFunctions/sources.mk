TEST_NAME := nmsis-dsp-benchmark-bayes
TEST_SRCS := \
  generated/benchmark/BayesFunctions/runner.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

