TEST_NAME := nmsis-dsp-benchmark-distance-cosine_distance_riscv_cosine_distance_f32
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/cosine_distance_riscv_cosine_distance_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_cosine_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_cosine_distance_f32.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_power_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

