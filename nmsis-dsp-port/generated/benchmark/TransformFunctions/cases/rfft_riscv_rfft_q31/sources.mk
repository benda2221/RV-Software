TEST_NAME := nmsis-dsp-benchmark-transform-rfft_riscv_rfft_q31
TEST_SRCS := \
  generated/benchmark/TransformFunctions/cases/rfft_riscv_rfft_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/TransformFunctions/rfft/test_riscv_rfft_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_rfft_init_q31.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_rfft_q31.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_cfft_q31.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_shift_q31.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_bitreversal2.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_cfft_radix4_q31.c \
  vendor/NMSIS/DSP/Source/TransformFunctions/riscv_bitreversal.c \
  port/src/compat_runtime.c \

