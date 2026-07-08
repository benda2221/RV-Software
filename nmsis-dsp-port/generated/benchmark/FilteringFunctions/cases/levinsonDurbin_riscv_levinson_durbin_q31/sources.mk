TEST_NAME := nmsis-dsp-benchmark-filtering-levinsondurbin_riscv_levinson_durbin_q31
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/levinsonDurbin_riscv_levinson_durbin_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_levinson_durbin_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_levinson_durbin_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_divide_q15.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_abs_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_cos_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

