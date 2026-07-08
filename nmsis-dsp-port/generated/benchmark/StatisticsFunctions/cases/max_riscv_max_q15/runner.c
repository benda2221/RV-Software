#include <stdio.h>
extern void max_riscv_max_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/max_riscv_max_q15\n");
    printf("RUN max_riscv_max_q15\n");
    max_riscv_max_q15();
    printf("PASS benchmark/StatisticsFunctions/max_riscv_max_q15 count=%d\n", 1);
    return 0;
}
