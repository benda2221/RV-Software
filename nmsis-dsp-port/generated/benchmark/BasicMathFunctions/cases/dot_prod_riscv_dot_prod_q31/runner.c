#include <stdio.h>
extern void dot_prod_riscv_dot_prod_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/dot_prod_riscv_dot_prod_q31\n");
    printf("RUN dot_prod_riscv_dot_prod_q31\n");
    dot_prod_riscv_dot_prod_q31();
    printf("PASS benchmark/BasicMathFunctions/dot_prod_riscv_dot_prod_q31 count=%d\n", 1);
    return 0;
}
