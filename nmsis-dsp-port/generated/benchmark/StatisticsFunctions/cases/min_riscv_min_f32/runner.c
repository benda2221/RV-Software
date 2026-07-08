#include <stdio.h>
extern void min_riscv_min_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/min_riscv_min_f32\n");
    printf("RUN min_riscv_min_f32\n");
    min_riscv_min_f32();
    printf("PASS benchmark/StatisticsFunctions/min_riscv_min_f32 count=%d\n", 1);
    return 0;
}
