#include <stdio.h>
extern void kullbackLeibler_riscv_kullback_leibler_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__StatisticsFunctions__vendor__NMSIS__DSP__Benchmark__StatisticsFunctions__test_riscv_kullback_leibler_f64\n");
    printf("RUN kullbackLeibler_riscv_kullback_leibler_f64\n");
    kullbackLeibler_riscv_kullback_leibler_f64();
    printf("PASS skipped-probe/benchmark__StatisticsFunctions__vendor__NMSIS__DSP__Benchmark__StatisticsFunctions__test_riscv_kullback_leibler_f64 count=%d\n", 1);
    return 0;
}
