TEST_NAME := nmsis-dsp-legacy-filteringfunction-levinsondurbin__levinson_durbin
TEST_SRCS := \
  generated/legacy/FilteringFunction/cases/levinsonDurbin__levinson_durbin/runner.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/levinsonDurbin/levinson_durbin.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_divide_q15.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_abs_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

