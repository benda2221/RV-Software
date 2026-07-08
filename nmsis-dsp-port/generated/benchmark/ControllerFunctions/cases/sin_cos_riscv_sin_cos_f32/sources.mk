TEST_NAME := nmsis-dsp-benchmark-controller-sin_cos_riscv_sin_cos_f32
TEST_SRCS := \
  generated/benchmark/ControllerFunctions/cases/sin_cos_riscv_sin_cos_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_sin_cos_f32.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_sin_cos_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

