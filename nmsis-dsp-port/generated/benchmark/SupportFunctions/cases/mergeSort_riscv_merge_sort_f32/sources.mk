TEST_NAME := nmsis-dsp-benchmark-support-mergesort_riscv_merge_sort_f32
TEST_SRCS := \
  generated/benchmark/SupportFunctions/cases/mergeSort_riscv_merge_sort_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_merge_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_merge_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_merge_sort_init_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

