TEST_NAME := nmsis-dsp-legacy-filteringfunction-firlatticepart__riscv_fir
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/FilteringFunction/firLatticePart/riscv_fir.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/firLatticePart/fir_lattice.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_lattice_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_lattice_init_f32.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_lattice_init_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_lattice_init_q31.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_lattice_q15.c \
  vendor/NMSIS/DSP/Source/FilteringFunctions/riscv_fir_lattice_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q15.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_float_to_q31.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q15_to_float.c \
  vendor/NMSIS/DSP/Source/SupportFunctions/riscv_q31_to_float.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

