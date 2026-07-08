#include <stdio.h>
extern void std_riscv_std_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/std_riscv_std_q31\n");
    printf("RUN std_riscv_std_q31\n");
    std_riscv_std_q31();
    printf("PASS benchmark/StatisticsFunctions/std_riscv_std_q31 count=%d\n", 1);
    return 0;
}
