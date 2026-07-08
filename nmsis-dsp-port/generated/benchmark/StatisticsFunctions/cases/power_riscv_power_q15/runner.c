#include <stdio.h>
extern void power_riscv_power_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/power_riscv_power_q15\n");
    printf("RUN power_riscv_power_q15\n");
    power_riscv_power_q15();
    printf("PASS benchmark/StatisticsFunctions/power_riscv_power_q15 count=%d\n", 1);
    return 0;
}
