TEST_NAME := nmsis-dsp-legacy-controllerfunctions-riscv_controller
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/ControllerFunctions/riscv_controller.c \
  vendor/NMSIS/DSP/Test/ControllerFunctions/ref_riscv_controller.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q31.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_pid_init_f32.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_pid_init_q15.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_pid_init_q31.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_sin_cos_f32.c \
  vendor/NMSIS/DSP/Source/ControllerFunctions/riscv_sin_cos_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

