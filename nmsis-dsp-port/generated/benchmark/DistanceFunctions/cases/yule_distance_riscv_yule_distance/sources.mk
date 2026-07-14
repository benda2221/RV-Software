TEST_NAME := nmsis-dsp-benchmark-distance-yule_distance_riscv_yule_distance
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/yule_distance_riscv_yule_distance/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_yule_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_yule_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_boolean_distance.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

