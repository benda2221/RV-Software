TEST_NAME := nmsis-dsp-benchmark-distance-correlation_distance_riscv_correlation_distance_f32
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/correlation_distance_riscv_correlation_distance_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_correlation_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_correlation_distance_f32.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_mean_f32.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_offset_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_power_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

