#include <stdio.h>
extern void canberra_distance_riscv_canberra_distance_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_canberra_distance_f16\n");
    printf("RUN canberra_distance_riscv_canberra_distance_f16\n");
    canberra_distance_riscv_canberra_distance_f16();
    printf("PASS skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_canberra_distance_f16 count=%d\n", 1);
    return 0;
}
