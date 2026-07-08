#include <stdio.h>
extern void absmax_riscv_absmax_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absmax_riscv_absmax_f32\n");
    printf("RUN absmax_riscv_absmax_f32\n");
    absmax_riscv_absmax_f32();
    printf("PASS benchmark/StatisticsFunctions/absmax_riscv_absmax_f32 count=%d\n", 1);
    return 0;
}
