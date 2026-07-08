TEST_NAME := nmsis-dsp-benchmark-controller-inv_park_riscv_inv_park_f32
TEST_SRCS := \
  generated/benchmark/ControllerFunctions/cases/inv_park_riscv_inv_park_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_inv_park_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

