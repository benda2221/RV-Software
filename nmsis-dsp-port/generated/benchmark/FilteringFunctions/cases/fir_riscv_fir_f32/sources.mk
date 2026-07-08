TEST_NAME := nmsis-dsp-benchmark-filtering-fir_riscv_fir_f32
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/fir_riscv_fir_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_fir_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_init_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_copy_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

