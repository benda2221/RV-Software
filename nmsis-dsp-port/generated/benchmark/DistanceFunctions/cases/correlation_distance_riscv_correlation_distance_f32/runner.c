#include <stdio.h>
extern void correlation_distance_riscv_correlation_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/correlation_distance_riscv_correlation_distance_f32\n");
    printf("RUN correlation_distance_riscv_correlation_distance_f32\n");
    correlation_distance_riscv_correlation_distance_f32();
    printf("PASS benchmark/DistanceFunctions/correlation_distance_riscv_correlation_distance_f32 count=%d\n", 1);
    return 0;
}
