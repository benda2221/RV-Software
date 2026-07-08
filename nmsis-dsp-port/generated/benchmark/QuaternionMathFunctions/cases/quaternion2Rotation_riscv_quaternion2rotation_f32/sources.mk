TEST_NAME := nmsis-dsp-benchmark-quaternionmath-quaternion2rotation_riscv_quaternion2rotation_f32
TEST_SRCS := \
  generated/benchmark/QuaternionMathFunctions/cases/quaternion2Rotation_riscv_quaternion2rotation_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/QuaternionMathFunctions/test_riscv_quaternion2rotation_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_quaternion2rotation_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

