TEST_NAME := nmsis-dsp-legacy-matrixfunctions-f16part__riscv_matrix
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/MatrixFunctions/f16Part/riscv_matrix.c \
  vendor/NMSIS/DSP/Test/MatrixFunctions/f16Part/ref_riscv_matrix.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_add_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_cholesky_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_cmplx_mult_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_inverse_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_scale_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_solve_lower_triangular_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_solve_upper_triangular_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_sub_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_trans_f16.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_vec_mult_f16.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

