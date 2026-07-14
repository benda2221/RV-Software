#include <stdio.h>
extern void entropy_riscv_entropy_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/entropy_riscv_entropy_f32\n");
    printf("RUN entropy_riscv_entropy_f32\n");
    entropy_riscv_entropy_f32();
    printf("PASS benchmark/StatisticsFunctions/entropy_riscv_entropy_f32 count=%d\n", 1);
    return 0;
}
