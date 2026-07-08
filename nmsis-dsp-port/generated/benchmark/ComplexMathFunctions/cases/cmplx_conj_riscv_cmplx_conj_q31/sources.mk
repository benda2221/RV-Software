TEST_NAME := nmsis-dsp-benchmark-complexmath-cmplx_conj_riscv_cmplx_conj_q31
TEST_SRCS := \
  generated/benchmark/ComplexMathFunctions/cases/cmplx_conj_riscv_cmplx_conj_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/ComplexMathFunctions/test_riscv_cmplx_conj_q31.c \
  vendor/NMSIS/DSP/Source/ComplexMathFunctions/riscv_cmplx_conj_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

