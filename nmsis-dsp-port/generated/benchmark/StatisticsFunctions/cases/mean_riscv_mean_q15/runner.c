#include <stdio.h>
extern void mean_riscv_mean_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/mean_riscv_mean_q15\n");
    printf("RUN mean_riscv_mean_q15\n");
    mean_riscv_mean_q15();
    printf("PASS benchmark/StatisticsFunctions/mean_riscv_mean_q15 count=%d\n", 1);
    return 0;
}
