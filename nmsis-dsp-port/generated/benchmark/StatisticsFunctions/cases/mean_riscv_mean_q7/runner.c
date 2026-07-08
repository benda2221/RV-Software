#include <stdio.h>
extern void mean_riscv_mean_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/mean_riscv_mean_q7\n");
    printf("RUN mean_riscv_mean_q7\n");
    mean_riscv_mean_q7();
    printf("PASS benchmark/StatisticsFunctions/mean_riscv_mean_q7 count=%d\n", 1);
    return 0;
}
