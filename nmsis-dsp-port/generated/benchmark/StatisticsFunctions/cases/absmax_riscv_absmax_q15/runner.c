#include <stdio.h>
extern void absmax_riscv_absmax_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absmax_riscv_absmax_q15\n");
    printf("RUN absmax_riscv_absmax_q15\n");
    absmax_riscv_absmax_q15();
    printf("PASS benchmark/StatisticsFunctions/absmax_riscv_absmax_q15 count=%d\n", 1);
    return 0;
}
