#include <stdio.h>
extern void absmin_riscv_absmin_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absmin_riscv_absmin_f32\n");
    printf("RUN absmin_riscv_absmin_f32\n");
    absmin_riscv_absmin_f32();
    printf("PASS benchmark/StatisticsFunctions/absmin_riscv_absmin_f32 count=%d\n", 1);
    return 0;
}
