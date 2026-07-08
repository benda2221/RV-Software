#include <stdio.h>
extern void braycurtis_distance_riscv_braycurtis_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/braycurtis_distance_riscv_braycurtis_distance_f32\n");
    printf("RUN braycurtis_distance_riscv_braycurtis_distance_f32\n");
    braycurtis_distance_riscv_braycurtis_distance_f32();
    printf("PASS benchmark/DistanceFunctions/braycurtis_distance_riscv_braycurtis_distance_f32 count=%d\n", 1);
    return 0;
}
