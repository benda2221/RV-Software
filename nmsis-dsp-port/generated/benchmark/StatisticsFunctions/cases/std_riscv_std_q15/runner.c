#include <stdio.h>
extern void std_riscv_std_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/std_riscv_std_q15\n");
    printf("RUN std_riscv_std_q15\n");
    std_riscv_std_q15();
    printf("PASS benchmark/StatisticsFunctions/std_riscv_std_q15 count=%d\n", 1);
    return 0;
}
