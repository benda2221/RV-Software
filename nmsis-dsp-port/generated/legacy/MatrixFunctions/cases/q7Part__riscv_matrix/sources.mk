TEST_NAME := nmsis-dsp-legacy-matrixfunctions-q7part__riscv_matrix
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/MatrixFunctions/q7Part/riscv_matrix.c \
  vendor/NMSIS/DSP/Test/MatrixFunctions/q7Part/ref_riscv_matrix.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_init_q7.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_mult_q7.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_vec_mult_q7.c \
  vendor/NMSIS/DSP/Source/MatrixFunctions/riscv_mat_trans_q7.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

