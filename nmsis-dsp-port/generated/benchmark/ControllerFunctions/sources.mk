TEST_NAME := nmsis-dsp-benchmark-controller
TEST_SRCS := \
  generated/benchmark/ControllerFunctions/runner.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_clarke_f32.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_clarke_q31.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_inv_clarke_f32.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_inv_clarke_q31.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_inv_park_f32.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_park_f32.c \
  vendor/NMSIS/DSP/Benchmark/ControllerFunctions/test_riscv_pid_f32.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_pid_init_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

