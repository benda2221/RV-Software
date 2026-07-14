TEST_NAME := nmsis-dsp-benchmark-distance-jaccard_distance_riscv_jaccard_distance
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/jaccard_distance_riscv_jaccard_distance/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_jaccard_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_jaccard_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_boolean_distance.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

