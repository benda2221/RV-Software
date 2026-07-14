TEST_NAME := nmsis-dsp-legacy-distancefunctions-ref_riscv_distance
TEST_SRCS := \
  generated/legacy/DistanceFunctions/cases/ref_riscv_distance/runner.c \
  vendor/NMSIS/DSP/Test/DistanceFunctions/ref_riscv_distance.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_power_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

