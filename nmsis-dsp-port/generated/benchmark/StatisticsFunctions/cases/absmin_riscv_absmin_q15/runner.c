#include <stdio.h>
extern void absmin_riscv_absmin_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absmin_riscv_absmin_q15\n");
    printf("RUN absmin_riscv_absmin_q15\n");
    absmin_riscv_absmin_q15();
    printf("PASS benchmark/StatisticsFunctions/absmin_riscv_absmin_q15 count=%d\n", 1);
    return 0;
}
