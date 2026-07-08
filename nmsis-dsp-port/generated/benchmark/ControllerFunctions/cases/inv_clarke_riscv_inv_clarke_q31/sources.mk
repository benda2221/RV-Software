TEST_NAME := nmsis-dsp-benchmark-controller-inv_clarke_riscv_inv_clarke_q31
TEST_SRCS := \
  generated/benchmark/ControllerFunctions/cases/inv_clarke_riscv_inv_clarke_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_inv_clarke_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

