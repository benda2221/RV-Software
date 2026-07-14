TEST_NAME := nmsis-dsp-benchmark-transform-rfft_riscv_rfft_fast_f32
TEST_SRCS := \
  generated/benchmark/TransformFunctions/cases/rfft_riscv_rfft_fast_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/TransformFunctions/rfft/test_riscv_rfft_fast_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_rfft_fast_f32.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_rfft_fast_init_f32.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_cfft_f32.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_cfft_init_f32.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_bitreversal2.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_cfft_radix8_f32.c \
  port/src/compat_runtime.c \

