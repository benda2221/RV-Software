#include <stdio.h>
extern void var_riscv_var_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/var_riscv_var_f32\n");
    printf("RUN var_riscv_var_f32\n");
    var_riscv_var_f32();
    printf("PASS benchmark/StatisticsFunctions/var_riscv_var_f32 count=%d\n", 1);
    return 0;
}
