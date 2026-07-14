TEST_NAME := nmsis-dsp-benchmark-transform-rfft_riscv_rfft_f32
TEST_SRCS := \
  generated/benchmark/TransformFunctions/cases/rfft_riscv_rfft_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/TransformFunctions/rfft/test_riscv_rfft_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_rfft_f32.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_rfft_init_f32.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_bitreversal.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_cfft_radix4_f32.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_cfft_radix4_init_f32.c \
  port/src/compat_runtime.c \

