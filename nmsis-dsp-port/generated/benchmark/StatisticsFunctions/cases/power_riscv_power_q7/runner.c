#include <stdio.h>
extern void power_riscv_power_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/power_riscv_power_q7\n");
    printf("RUN power_riscv_power_q7\n");
    power_riscv_power_q7();
    printf("PASS benchmark/StatisticsFunctions/power_riscv_power_q7 count=%d\n", 1);
    return 0;
}
