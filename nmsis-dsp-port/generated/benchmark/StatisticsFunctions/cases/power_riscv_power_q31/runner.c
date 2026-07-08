#include <stdio.h>
extern void power_riscv_power_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/power_riscv_power_q31\n");
    printf("RUN power_riscv_power_q31\n");
    power_riscv_power_q31();
    printf("PASS benchmark/StatisticsFunctions/power_riscv_power_q31 count=%d\n", 1);
    return 0;
}
