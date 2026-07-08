#include <stdio.h>
extern void mse_riscv_mse_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/mse_riscv_mse_q7\n");
    printf("RUN mse_riscv_mse_q7\n");
    mse_riscv_mse_q7();
    printf("PASS benchmark/StatisticsFunctions/mse_riscv_mse_q7 count=%d\n", 1);
    return 0;
}
