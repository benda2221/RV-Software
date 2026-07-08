#include <stdio.h>
extern void canberra_distance_riscv_canberra_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/canberra_distance_riscv_canberra_distance_f32\n");
    printf("RUN canberra_distance_riscv_canberra_distance_f32\n");
    canberra_distance_riscv_canberra_distance_f32();
    printf("PASS benchmark/DistanceFunctions/canberra_distance_riscv_canberra_distance_f32 count=%d\n", 1);
    return 0;
}
