#include <stdio.h>
extern void sqrt_riscv_sqrt_q15(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/sqrt_riscv_sqrt_q15\n");
    printf("RUN sqrt_riscv_sqrt_q15\n");
    sqrt_riscv_sqrt_q15();
    printf("PASS benchmark/FastMathFunctions/sqrt_riscv_sqrt_q15 count=%d\n", 1);
    return 0;
}
