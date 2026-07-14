#include <stdio.h>
extern void correlate_riscv_correlate_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_correlate_f16\n");
    printf("RUN correlate_riscv_correlate_f16\n");
    correlate_riscv_correlate_f16();
    printf("PASS skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_correlate_f16 count=%d\n", 1);
    return 0;
}
