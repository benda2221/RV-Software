#include <stdio.h>
extern void mean_riscv_mean_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/mean_riscv_mean_f32\n");
    printf("RUN mean_riscv_mean_f32\n");
    mean_riscv_mean_f32();
    printf("PASS benchmark/StatisticsFunctions/mean_riscv_mean_f32 count=%d\n", 1);
    return 0;
}
