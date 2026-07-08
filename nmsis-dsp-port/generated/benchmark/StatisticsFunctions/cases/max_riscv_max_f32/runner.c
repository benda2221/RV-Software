#include <stdio.h>
extern void max_riscv_max_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/max_riscv_max_f32\n");
    printf("RUN max_riscv_max_f32\n");
    max_riscv_max_f32();
    printf("PASS benchmark/StatisticsFunctions/max_riscv_max_f32 count=%d\n", 1);
    return 0;
}
