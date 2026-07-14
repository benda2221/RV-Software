#include <stdio.h>
extern void cosine_distance_riscv_cosine_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/cosine_distance_riscv_cosine_distance_f32\n");
    printf("RUN cosine_distance_riscv_cosine_distance_f32\n");
    cosine_distance_riscv_cosine_distance_f32();
    printf("PASS benchmark/DistanceFunctions/cosine_distance_riscv_cosine_distance_f32 count=%d\n", 1);
    return 0;
}
