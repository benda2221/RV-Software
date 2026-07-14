TEST_NAME := nmsis-dsp-legacy-distancefunctions-riscv_distance
TEST_SRCS := \
  vendor/NMSIS/DSP/Test/DistanceFunctions/riscv_distance.c \
  vendor/NMSIS/DSP/Test/DistanceFunctions/ref_riscv_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_braycurtis_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_canberra_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_chebyshev_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_cityblock_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_cosine_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_dice_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_euclidean_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_hamming_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_jaccard_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_jensenshannon_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_kulsinski_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_minkowski_distance_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_rogerstanimoto_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_russellrao_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_sokalmichener_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_sokalsneath_distance.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_yule_distance.c \
  vendor/NMSIS/DSP/Source/BasicMathFunctions/riscv_dot_prod_f32.c \
  vendor/NMSIS/DSP/Source/StatisticsFunctions/riscv_power_f32.c \
  vendor/NMSIS/DSP/Source/DistanceFunctions/riscv_boolean_distance.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_common_tables.c \
  vendor/NMSIS/DSP/Source/CommonTables/riscv_const_structs.c \
  port/src/ref_matrix_f32_subset.c \
  port/src/compat_runtime.c \

