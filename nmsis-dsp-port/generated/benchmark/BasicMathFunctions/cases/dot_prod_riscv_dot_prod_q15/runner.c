#include <stdio.h>
extern void dot_prod_riscv_dot_prod_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/dot_prod_riscv_dot_prod_q15\n");
    printf("RUN dot_prod_riscv_dot_prod_q15\n");
    dot_prod_riscv_dot_prod_q15();
    printf("PASS benchmark/BasicMathFunctions/dot_prod_riscv_dot_prod_q15 count=%d\n", 1);
    return 0;
}
