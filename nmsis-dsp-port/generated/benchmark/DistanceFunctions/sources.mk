TEST_NAME := nmsis-dsp-benchmark-distance
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_braycurtis_distance_f32.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_canberra_distance_f32.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_chebyshev_distance_f32.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_cityblock_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_braycurtis_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_canberra_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_chebyshev_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_cityblock_distance_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

