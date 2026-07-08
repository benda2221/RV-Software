#include <stdio.h>
extern void mean_riscv_mean_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/mean_riscv_mean_q31\n");
    printf("RUN mean_riscv_mean_q31\n");
    mean_riscv_mean_q31();
    printf("PASS benchmark/StatisticsFunctions/mean_riscv_mean_q31 count=%d\n", 1);
    return 0;
}
