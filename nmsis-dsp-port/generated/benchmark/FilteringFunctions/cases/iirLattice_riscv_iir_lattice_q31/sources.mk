TEST_NAME := nmsis-dsp-benchmark-filtering-iirlattice_riscv_iir_lattice_q31
TEST_SRCS := \
  generated/benchmark/FilteringFunctions/cases/iirLattice_riscv_iir_lattice_q31/runner.c \
  vendor/NMSIS/DSP/Benchmark/FilteringFunctions/test_riscv_iir_lattice_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_iir_lattice_init_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_iir_lattice_q31.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/compat_runtime.c \

