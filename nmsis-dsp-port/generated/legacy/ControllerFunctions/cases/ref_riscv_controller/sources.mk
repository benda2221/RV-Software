TEST_NAME := nmsis-dsp-legacy-controllerfunctions-ref_riscv_controller
TEST_SRCS := \
  generated/legacy/ControllerFunctions/cases/ref_riscv_controller/runner.c \
  vendor/NMSIS/DSP/Test/ControllerFunctions/ref_riscv_controller.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

