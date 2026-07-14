TEST_NAME := nmsis-dsp-benchmark-distance-sokalsneath_distance_riscv_sokalsneath_distance
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/sokalsneath_distance_riscv_sokalsneath_distance/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_sokalsneath_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_sokalsneath_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_boolean_distance.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

