#include <stdio.h>
extern void max_riscv_max_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/max_riscv_max_q7\n");
    printf("RUN max_riscv_max_q7\n");
    max_riscv_max_q7();
    printf("PASS benchmark/StatisticsFunctions/max_riscv_max_q7 count=%d\n", 1);
    return 0;
}
