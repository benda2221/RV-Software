#include <stdio.h>
extern void absmax_riscv_absmax_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__StatisticsFunctions__vendor__NMSIS__DSP__Benchmark__StatisticsFunctions__test_riscv_absmax_f16\n");
    printf("RUN absmax_riscv_absmax_f16\n");
    absmax_riscv_absmax_f16();
    printf("PASS skipped-probe/benchmark__StatisticsFunctions__vendor__NMSIS__DSP__Benchmark__StatisticsFunctions__test_riscv_absmax_f16 count=%d\n", 1);
    return 0;
}
