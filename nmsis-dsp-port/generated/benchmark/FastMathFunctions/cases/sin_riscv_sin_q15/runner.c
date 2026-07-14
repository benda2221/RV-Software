#include <stdio.h>
extern void sin_riscv_sin_q15(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/sin_riscv_sin_q15\n");
    printf("RUN sin_riscv_sin_q15\n");
    sin_riscv_sin_q15();
    printf("PASS benchmark/FastMathFunctions/sin_riscv_sin_q15 count=%d\n", 1);
    return 0;
}
