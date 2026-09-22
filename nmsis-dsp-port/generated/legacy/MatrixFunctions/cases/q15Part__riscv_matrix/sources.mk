TEST_NAME := nmsis-dsp-legacy-matrixfunctions-q15part__riscv_matrix
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/MatrixFunctions/q15Part/riscv_matrix.c \
  vendor/NMSIS/DSP/Test/MatrixFunctions/q15Part/ref_riscv_matrix.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_add_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_cmplx_mult_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_fast_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_scale_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_sub_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_trans_q15.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_vec_mult_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

