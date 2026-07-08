#include <stdio.h>
extern void absmax_riscv_absmax_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absmax_riscv_absmax_q31\n");
    printf("RUN absmax_riscv_absmax_q31\n");
    absmax_riscv_absmax_q31();
    printf("PASS benchmark/StatisticsFunctions/absmax_riscv_absmax_q31 count=%d\n", 1);
    return 0;
}
