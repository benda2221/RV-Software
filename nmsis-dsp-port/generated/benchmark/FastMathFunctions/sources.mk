TEST_NAME := nmsis-dsp-benchmark-fastmath
TEST_SRCS := \
  generated/benchmark/FastMathFunctions/runner.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_atan2_q15.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_atan2_q31.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_cos_q15.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_cos_q31.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_divide_q15.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_divide_q31.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_sqrt_q15.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_sqrt_q31.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_vlog_q15.c \
  vendor/NMSIS/DSP/Benchmark/FastMathFunctions/test_riscv_vlog_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_atan2_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_atan2_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_cos_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_cos_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_divide_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_divide_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_sqrt_q31.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_vlog_q15.c \
  vendor/NMSIS/DSP/Source/FastMathFunctions/riscv_vlog_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_abs_q15.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_abs_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

