TEST_NAME := nmsis-dsp-benchmark-filtering-firdecimate_riscv_fir_decimate_q31
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/firDecimate_riscv_fir_decimate_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_decimate_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_init_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

