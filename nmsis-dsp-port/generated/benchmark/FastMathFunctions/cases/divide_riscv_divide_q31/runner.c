#include <stdio.h>
extern void divide_riscv_divide_q31(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/divide_riscv_divide_q31\n");
    printf("RUN divide_riscv_divide_q31\n");
    divide_riscv_divide_q31();
    printf("PASS benchmark/FastMathFunctions/divide_riscv_divide_q31 count=%d\n", 1);
    return 0;
}
