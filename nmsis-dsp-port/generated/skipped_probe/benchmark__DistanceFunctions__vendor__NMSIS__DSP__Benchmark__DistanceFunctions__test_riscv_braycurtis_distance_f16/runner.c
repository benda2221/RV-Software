#include <stdio.h>
extern void braycurtis_distance_riscv_braycurtis_distance_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_braycurtis_distance_f16\n");
    printf("RUN braycurtis_distance_riscv_braycurtis_distance_f16\n");
    braycurtis_distance_riscv_braycurtis_distance_f16();
    printf("PASS skipped-probe/benchmark__DistanceFunctions__vendor__NMSIS__DSP__Benchmark__DistanceFunctions__test_riscv_braycurtis_distance_f16 count=%d\n", 1);
    return 0;
}
