#include <stdio.h>
extern void chebyshev_distance_riscv_chebyshev_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/chebyshev_distance_riscv_chebyshev_distance_f32\n");
    printf("RUN chebyshev_distance_riscv_chebyshev_distance_f32\n");
    chebyshev_distance_riscv_chebyshev_distance_f32();
    printf("PASS benchmark/DistanceFunctions/chebyshev_distance_riscv_chebyshev_distance_f32 count=%d\n", 1);
    return 0;
}
