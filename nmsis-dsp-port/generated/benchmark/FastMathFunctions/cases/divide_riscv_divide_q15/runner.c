#include <stdio.h>
extern void divide_riscv_divide_q15(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/divide_riscv_divide_q15\n");
    printf("RUN divide_riscv_divide_q15\n");
    divide_riscv_divide_q15();
    printf("PASS benchmark/FastMathFunctions/divide_riscv_divide_q15 count=%d\n", 1);
    return 0;
}
