TEST_NAME := nmsis-dsp-benchmark-filtering-firdecimate_riscv_fir_decimate_f32
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/firDecimate_riscv_fir_decimate_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_decimate_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_decimate_init_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

