#include <stdio.h>
extern void euclidean_distance_riscv_euclidean_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/euclidean_distance_riscv_euclidean_distance_f32\n");
    printf("RUN euclidean_distance_riscv_euclidean_distance_f32\n");
    euclidean_distance_riscv_euclidean_distance_f32();
    printf("PASS benchmark/DistanceFunctions/euclidean_distance_riscv_euclidean_distance_f32 count=%d\n", 1);
    return 0;
}
