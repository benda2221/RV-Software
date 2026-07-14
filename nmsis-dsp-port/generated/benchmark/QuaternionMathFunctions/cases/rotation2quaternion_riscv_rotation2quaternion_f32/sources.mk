TEST_NAME := nmsis-dsp-benchmark-quaternionmath-rotation2quaternion_riscv_rotation2quaternion_f32
TEST_SRCS := \
  generated/benchmark/QuaternionMathFunctions/cases/rotation2quaternion_riscv_rotation2quaternion_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/QuaternionMathFunctions/test_riscv_rotation2quaternion_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_rotation2quaternion_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

