#include <stdio.h>
extern void kullbackLeibler_riscv_kullback_leibler_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/kullbackLeibler_riscv_kullback_leibler_f32\n");
    printf("RUN kullbackLeibler_riscv_kullback_leibler_f32\n");
    kullbackLeibler_riscv_kullback_leibler_f32();
    printf("PASS benchmark/StatisticsFunctions/kullbackLeibler_riscv_kullback_leibler_f32 count=%d\n", 1);
    return 0;
}
