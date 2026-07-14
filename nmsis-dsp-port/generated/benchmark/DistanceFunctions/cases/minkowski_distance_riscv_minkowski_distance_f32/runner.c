#include <stdio.h>
extern void minkowski_distance_riscv_minkowski_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/minkowski_distance_riscv_minkowski_distance_f32\n");
    printf("RUN minkowski_distance_riscv_minkowski_distance_f32\n");
    minkowski_distance_riscv_minkowski_distance_f32();
    printf("PASS benchmark/DistanceFunctions/minkowski_distance_riscv_minkowski_distance_f32 count=%d\n", 1);
    return 0;
}
