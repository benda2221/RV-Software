#include <stdio.h>
extern void var_riscv_var_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/var_riscv_var_q31\n");
    printf("RUN var_riscv_var_q31\n");
    var_riscv_var_q31();
    printf("PASS benchmark/StatisticsFunctions/var_riscv_var_q31 count=%d\n", 1);
    return 0;
}
