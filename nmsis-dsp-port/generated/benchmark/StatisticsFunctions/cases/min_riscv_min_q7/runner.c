#include <stdio.h>
extern void min_riscv_min_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/min_riscv_min_q7\n");
    printf("RUN min_riscv_min_q7\n");
    min_riscv_min_q7();
    printf("PASS benchmark/StatisticsFunctions/min_riscv_min_q7 count=%d\n", 1);
    return 0;
}
