TEST_NAME := nmsis-dsp-benchmark-svm-svm_riscv_svm_rbf_predict_f32
TEST_SRCS := \
  generated/benchmark/SVMFunctions/cases/svm_riscv_svm_rbf_predict_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/SVMFunctions/test_riscv_svm_rbf_predict_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_rbf_init_f32.c \
  vendor/NMSIS/DSP/Source/SVMFunctions/riscv_svm_rbf_predict_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

