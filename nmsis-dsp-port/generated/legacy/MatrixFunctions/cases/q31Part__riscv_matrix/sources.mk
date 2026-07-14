TEST_NAME := nmsis-dsp-legacy-matrixfunctions-q31part__riscv_matrix
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/MatrixFunctions/q31Part/riscv_matrix.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Test/MatrixFunctions/q31Part/ref_riscv_matrix.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_add_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_cmplx_mult_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_fast_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_opt_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_scale_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_sub_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_trans_q31.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_vec_mult_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

