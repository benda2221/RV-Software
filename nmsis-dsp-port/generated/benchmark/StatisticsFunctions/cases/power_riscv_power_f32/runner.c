#include <stdio.h>
extern void power_riscv_power_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/power_riscv_power_f32\n");
    printf("RUN power_riscv_power_f32\n");
    power_riscv_power_f32();
    printf("PASS benchmark/StatisticsFunctions/power_riscv_power_f32 count=%d\n", 1);
    return 0;
}
