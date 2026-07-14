TEST_NAME := nmsis-dsp-benchmark-distance-jensenshannon_distance_riscv_jensenshannon_distance_f32
TEST_SRCS := \
  generated/benchmark/DistanceFunctions/cases/jensenshannon_distance_riscv_jensenshannon_distance_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/DistanceFunctions/test_riscv_jensenshannon_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_jensenshannon_distance_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

