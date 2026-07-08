TEST_NAME := nmsis-dsp-benchmark-controller-pid_riscv_pid_f32
TEST_SRCS := \
  generated/benchmark/ControllerFunctions/cases/pid_riscv_pid_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_pid_f32.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_pid_init_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

