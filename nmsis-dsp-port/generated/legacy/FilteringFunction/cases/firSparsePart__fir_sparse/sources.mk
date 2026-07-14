TEST_NAME := nmsis-dsp-legacy-filteringfunction-firsparsepart__fir_sparse
TEST_SRCS := \
  generated/legacy/FilteringFunction/cases/firSparsePart__fir_sparse/runner.c \
  vendor/NMSIS/DSP/Test/FilteringFunction/firSparsePart/fir_sparse.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

