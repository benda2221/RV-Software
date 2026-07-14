#include <stdio.h>
extern void chebyshev_distance_riscv_chebyshev_distance_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_chebyshev_distance_f64\n");
    printf("RUN chebyshev_distance_riscv_chebyshev_distance_f64\n");
    chebyshev_distance_riscv_chebyshev_distance_f64();
    printf("PASS skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_chebyshev_distance_f64 count=%d\n", 1);
    return 0;
}
