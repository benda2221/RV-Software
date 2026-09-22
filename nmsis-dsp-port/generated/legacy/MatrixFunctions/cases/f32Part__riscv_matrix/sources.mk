TEST_NAME := nmsis-dsp-legacy-matrixfunctions-f32part__riscv_matrix
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/MatrixFunctions/f32Part/riscv_matrix.c \
  port/src/ref_matrix_f32_subset.c \
  vendor/NMSIS/DSP/Test/MatrixFunctions/f32Part/ref_riscv_matrix.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_add_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_cholesky_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_cholesky_f64.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_cmplx_mult_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_f64.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_inverse_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_ldlt_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_ldlt_f64.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_scale_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_solve_lower_triangular_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_solve_lower_triangular_f64.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_solve_upper_triangular_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_solve_upper_triangular_f64.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_sub_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_trans_f32.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_vec_mult_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

