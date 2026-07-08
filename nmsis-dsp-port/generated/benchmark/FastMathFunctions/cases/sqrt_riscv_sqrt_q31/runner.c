#include <stdio.h>
extern void sqrt_riscv_sqrt_q31(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/sqrt_riscv_sqrt_q31\n");
    printf("RUN sqrt_riscv_sqrt_q31\n");
    sqrt_riscv_sqrt_q31();
    printf("PASS benchmark/FastMathFunctions/sqrt_riscv_sqrt_q31 count=%d\n", 1);
    return 0;
}
