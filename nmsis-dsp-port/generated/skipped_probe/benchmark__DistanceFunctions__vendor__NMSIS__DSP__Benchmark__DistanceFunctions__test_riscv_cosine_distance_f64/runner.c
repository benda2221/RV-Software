#include <stdio.h>
extern void cosine_distance_riscv_cosine_distance_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_cosine_distance_f64\n");
    printf("RUN cosine_distance_riscv_cosine_distance_f64\n");
    cosine_distance_riscv_cosine_distance_f64();
    printf("PASS skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_cosine_distance_f64 count=%d\n", 1);
    return 0;
}
