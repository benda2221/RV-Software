#include <stdio.h>
extern void mse_riscv_mse_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/mse_riscv_mse_q31\n");
    printf("RUN mse_riscv_mse_q31\n");
    mse_riscv_mse_q31();
    printf("PASS benchmark/StatisticsFunctions/mse_riscv_mse_q31 count=%d\n", 1);
    return 0;
}
