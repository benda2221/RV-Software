TEST_NAME := nmsis-dsp-benchmark-support-sort_riscv_sort_f32
TEST_SRCS := \
  generated/benchmark/SupportFunctions/cases/sort_riscv_sort_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/SupportFunctions/test_riscv_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_sort_init_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_bitonic_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_bubble_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_heap_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_insertion_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_quick_sort_f32.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_selection_sort_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

