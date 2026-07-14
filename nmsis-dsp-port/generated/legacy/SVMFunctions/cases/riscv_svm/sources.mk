TEST_NAME := nmsis-dsp-legacy-svmfunctions-riscv_svm
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/SVMFunctions/riscv_svm.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_linear_init_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_linear_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_linear_predict_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_linear_predict_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_polynomial_init_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_polynomial_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_polynomial_predict_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_polynomial_predict_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_rbf_init_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_rbf_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_rbf_predict_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_rbf_predict_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_sigmoid_init_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_sigmoid_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_sigmoid_predict_f16.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_sigmoid_predict_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

