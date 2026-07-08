TEST_NAME := nmsis-dsp-benchmark-filtering-fir_riscv_fir_q15
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/fir_riscv_fir_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_init_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_fast_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

