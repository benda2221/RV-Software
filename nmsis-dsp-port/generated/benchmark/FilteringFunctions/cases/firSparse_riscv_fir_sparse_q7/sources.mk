TEST_NAME := nmsis-dsp-benchmark-filtering-firsparse_riscv_fir_sparse_q7
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/firSparse_riscv_fir_sparse_q7/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_sparse_q7.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_sparse_init_q7.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_sparse_q7.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q7.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

