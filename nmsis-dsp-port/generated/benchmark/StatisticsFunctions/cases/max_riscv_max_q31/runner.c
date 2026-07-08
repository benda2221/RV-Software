#include <stdio.h>
extern void max_riscv_max_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/max_riscv_max_q31\n");
    printf("RUN max_riscv_max_q31\n");
    max_riscv_max_q31();
    printf("PASS benchmark/StatisticsFunctions/max_riscv_max_q31 count=%d\n", 1);
    return 0;
}
