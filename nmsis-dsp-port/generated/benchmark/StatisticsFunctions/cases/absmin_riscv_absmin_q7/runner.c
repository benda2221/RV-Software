#include <stdio.h>
extern void absmin_riscv_absmin_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absmin_riscv_absmin_q7\n");
    printf("RUN absmin_riscv_absmin_q7\n");
    absmin_riscv_absmin_q7();
    printf("PASS benchmark/StatisticsFunctions/absmin_riscv_absmin_q7 count=%d\n", 1);
    return 0;
}
