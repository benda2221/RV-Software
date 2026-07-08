TEST_NAME := nmsis-dsp-benchmark-complexmath-cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_q15
TEST_SRCS := \
  generated/benchmark/ComplexMathFunctions/cases/cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_q15/runner.c \
  vendor/NMSIS/DSP/Benchmark/ComplexMathFunctions/test_riscv_cmplx_mult_cmplx_q15.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_mult_cmplx_q15.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

