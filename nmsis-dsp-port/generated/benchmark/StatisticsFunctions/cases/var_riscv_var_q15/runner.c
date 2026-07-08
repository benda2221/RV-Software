#include <stdio.h>
extern void var_riscv_var_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/var_riscv_var_q15\n");
    printf("RUN var_riscv_var_q15\n");
    var_riscv_var_q15();
    printf("PASS benchmark/StatisticsFunctions/var_riscv_var_q15 count=%d\n", 1);
    return 0;
}
