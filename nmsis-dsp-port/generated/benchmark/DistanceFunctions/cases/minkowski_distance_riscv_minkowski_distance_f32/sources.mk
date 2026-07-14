TEST_NAME := nmsis-dsp-benchmark-distance-minkowski_distance_riscv_minkowski_distance_f32
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/minkowski_distance_riscv_minkowski_distance_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_minkowski_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_minkowski_distance_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

