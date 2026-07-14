TEST_NAME := nmsis-dsp-benchmark-filtering-lmsnorm_riscv_lms_norm_f32
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/lmsNorm_riscv_lms_norm_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_lms_norm_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_lms_norm_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_lms_norm_init_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

