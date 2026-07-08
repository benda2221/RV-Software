#include <stdio.h>
extern void min_riscv_min_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/min_riscv_min_q15\n");
    printf("RUN min_riscv_min_q15\n");
    min_riscv_min_q15();
    printf("PASS benchmark/StatisticsFunctions/min_riscv_min_q15 count=%d\n", 1);
    return 0;
}
