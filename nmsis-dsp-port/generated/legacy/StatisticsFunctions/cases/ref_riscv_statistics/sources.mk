TEST_NAME := nmsis-dsp-legacy-statisticsfunctions-ref_riscv_statistics
TEST_SRCS := \
  generated/legacy/StatisticsFunctions/cases/ref_riscv_statistics/runner.c \
  vendor/NMSIS/DSP/Test/StatisticsFunctions/ref_riscv_statistics.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

