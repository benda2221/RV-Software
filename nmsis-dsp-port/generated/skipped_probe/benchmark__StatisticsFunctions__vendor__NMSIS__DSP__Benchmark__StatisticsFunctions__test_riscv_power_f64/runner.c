#include <stdio.h>
extern void power_riscv_power_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__StatisticsFunctions__vendor__NMSIS__DSP__Benchmark__StatisticsFunctions__test_riscv_power_f64\n");
    printf("RUN power_riscv_power_f64\n");
    power_riscv_power_f64();
    printf("PASS skipped-probe/benchmark__StatisticsFunctions__vendor__NMSIS__DSP__Benchmark__StatisticsFunctions__test_riscv_power_f64 count=%d\n", 1);
    return 0;
}
