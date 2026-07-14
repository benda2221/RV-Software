#include <stdio.h>
extern void cosine_distance_riscv_cosine_distance_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_cosine_distance_f16\n");
    printf("RUN cosine_distance_riscv_cosine_distance_f16\n");
    cosine_distance_riscv_cosine_distance_f16();
    printf("PASS skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_cosine_distance_f16 count=%d\n", 1);
    return 0;
}
