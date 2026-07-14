#include <stdio.h>
extern void euclidean_distance_riscv_euclidean_distance_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_euclidean_distance_f64\n");
    printf("RUN euclidean_distance_riscv_euclidean_distance_f64\n");
    euclidean_distance_riscv_euclidean_distance_f64();
    printf("PASS skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_euclidean_distance_f64 count=%d\n", 1);
    return 0;
}
