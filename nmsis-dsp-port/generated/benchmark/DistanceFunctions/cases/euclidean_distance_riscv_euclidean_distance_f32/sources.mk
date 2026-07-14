TEST_NAME := nmsis-dsp-benchmark-distance-euclidean_distance_riscv_euclidean_distance_f32
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/euclidean_distance_riscv_euclidean_distance_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_euclidean_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_euclidean_distance_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

