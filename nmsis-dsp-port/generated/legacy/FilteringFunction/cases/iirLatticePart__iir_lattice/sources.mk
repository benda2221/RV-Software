TEST_NAME := nmsis-dsp-legacy-filteringfunction-iirlatticepart__iir_lattice
TEST_SRCS := \
  generated/legacy/FilteringFunction/cases/iirLatticePart__iir_lattice/runner.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/iirLatticePart/iir_lattice.c \
  vendor/NMSIS/DSP/Test/HelperFunctions/ref_helper.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

