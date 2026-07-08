#include <stdio.h>
extern void cityblock_distance_riscv_cityblock_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/cityblock_distance_riscv_cityblock_distance_f32\n");
    printf("RUN cityblock_distance_riscv_cityblock_distance_f32\n");
    cityblock_distance_riscv_cityblock_distance_f32();
    printf("PASS benchmark/DistanceFunctions/cityblock_distance_riscv_cityblock_distance_f32 count=%d\n", 1);
    return 0;
}
