#include <stdio.h>
extern void std_riscv_std_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/std_riscv_std_f32\n");
    printf("RUN std_riscv_std_f32\n");
    std_riscv_std_f32();
    printf("PASS benchmark/StatisticsFunctions/std_riscv_std_f32 count=%d\n", 1);
    return 0;
}
