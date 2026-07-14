TEST_NAME := nmsis-dsp-benchmark-controller-pid_riscv_pid_q15
TEST_SRCS := \
  generated/benchmark/ControllerFunctions/cases/pid_riscv_pid_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_pid_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q15.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_pid_init_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

