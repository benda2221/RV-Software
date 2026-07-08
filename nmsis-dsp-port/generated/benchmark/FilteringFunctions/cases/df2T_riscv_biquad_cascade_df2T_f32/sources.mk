TEST_NAME := nmsis-dsp-benchmark-filtering-df2t_riscv_biquad_cascade_df2t_f32
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/df2T_riscv_biquad_cascade_df2T_f32/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_biquad_cascade_df2T_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df2T_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_biquad_cascade_df2T_init_f32.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

