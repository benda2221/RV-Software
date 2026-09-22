TEST_NAME := nmsis-dsp-legacy-filteringfunction-levinsondurbin__riscv_fir
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/FilteringFunction/levinsonDurbin/riscv_fir.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/levinsonDurbin/levinson_durbin.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_levinson_durbin_f16.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_levinson_durbin_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_levinson_durbin_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_divide_q15.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_abs_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

