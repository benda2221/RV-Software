#include <stdio.h>
extern void absmax_riscv_absmax_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absmax_riscv_absmax_q7\n");
    printf("RUN absmax_riscv_absmax_q7\n");
    absmax_riscv_absmax_q7();
    printf("PASS benchmark/StatisticsFunctions/absmax_riscv_absmax_q7 count=%d\n", 1);
    return 0;
}
