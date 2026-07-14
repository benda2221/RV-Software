TEST_NAME := nmsis-dsp-benchmark-distance-hamming_distance_riscv_hamming_distance
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/hamming_distance_riscv_hamming_distance/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_hamming_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_hamming_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_boolean_distance.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

