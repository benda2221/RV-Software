#include <stdio.h>
extern void mse_riscv_mse_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/mse_riscv_mse_q15\n");
    printf("RUN mse_riscv_mse_q15\n");
    mse_riscv_mse_q15();
    printf("PASS benchmark/StatisticsFunctions/mse_riscv_mse_q15 count=%d\n", 1);
    return 0;
}
