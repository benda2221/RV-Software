TEST_NAME := nmsis-dsp-benchmark-controller-clarke_riscv_clarke_q31
TEST_SRCS := \
  generated/benchmark/ControllerFunctions/cases/clarke_riscv_clarke_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_clarke_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

