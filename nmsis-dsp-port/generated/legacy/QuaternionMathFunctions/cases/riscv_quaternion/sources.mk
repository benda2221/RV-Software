TEST_NAME := nmsis-dsp-legacy-quaternionmathfunctions-riscv_quaternion
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/QuaternionMathFunctions/riscv_quaternion.c \
  vendor/NMSIS/DSP/Test/QuaternionMathFunctions/ref_riscv_quaternion.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_quaternion2rotation_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_quaternion_conjugate_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_quaternion_inverse_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_quaternion_norm_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_quaternion_normalize_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_quaternion_product_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_quaternion_product_single_f32.c \
  vendor/NMSIS/DSP/Source/QuaternionMathFunctions/riscv_rotation2quaternion_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

