#include <stdio.h>
extern void mse_riscv_mse_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/mse_riscv_mse_f32\n");
    printf("RUN mse_riscv_mse_f32\n");
    mse_riscv_mse_f32();
    printf("PASS benchmark/StatisticsFunctions/mse_riscv_mse_f32 count=%d\n", 1);
    return 0;
}
