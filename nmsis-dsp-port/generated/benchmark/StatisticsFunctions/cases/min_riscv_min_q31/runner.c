#include <stdio.h>
extern void min_riscv_min_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/min_riscv_min_q31\n");
    printf("RUN min_riscv_min_q31\n");
    min_riscv_min_q31();
    printf("PASS benchmark/StatisticsFunctions/min_riscv_min_q31 count=%d\n", 1);
    return 0;
}
