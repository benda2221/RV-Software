TEST_NAME := nmsis-dsp-legacy-quaternionmathfunctions-ref_riscv_quaternion
TEST_SRCS := \
  generated/legacy/QuaternionMathFunctions/cases/ref_riscv_quaternion/runner.c \
  vendor/NMSIS/DSP/Test/QuaternionMathFunctions/ref_riscv_quaternion.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

