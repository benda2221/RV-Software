TEST_NAME := nmsis-dsp-benchmark-distance-russellrao_distance_riscv_russellrao_distance
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/russellrao_distance_riscv_russellrao_distance/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_russellrao_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_russellrao_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_boolean_distance.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

