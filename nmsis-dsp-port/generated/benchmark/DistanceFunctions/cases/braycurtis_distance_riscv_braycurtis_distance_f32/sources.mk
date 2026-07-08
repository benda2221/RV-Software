TEST_NAME := nmsis-dsp-benchmark-distance-braycurtis_distance_riscv_braycurtis_distance_f32
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/braycurtis_distance_riscv_braycurtis_distance_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_braycurtis_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_braycurtis_distance_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

