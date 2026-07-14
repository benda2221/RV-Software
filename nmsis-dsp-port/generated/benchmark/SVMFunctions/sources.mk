TEST_NAME := nmsis-dsp-benchmark-svm
TEST_SRCS := \
  generated/benchmark/SVMFunctions/runner.c \
  vendor/NMSIS/DSP/Benchmark/SVMFunctions/test_riscv_svm_linear_predict_f32.c \
  vendor/NMSIS/DSP/Benchmark/SVMFunctions/test_riscv_svm_polynomial_predict_f32.c \
  vendor/NMSIS/DSP/Benchmark/SVMFunctions/test_riscv_svm_rbf_predict_f32.c \
  vendor/NMSIS/DSP/Benchmark/SVMFunctions/test_riscv_svm_sigmoid_predict_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_linear_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_linear_predict_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_polynomial_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_polynomial_predict_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_rbf_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_rbf_predict_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_sigmoid_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_sigmoid_predict_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

