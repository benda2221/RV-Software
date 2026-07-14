#include <stdio.h>
extern void sin_riscv_sin_q31(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/sin_riscv_sin_q31\n");
    printf("RUN sin_riscv_sin_q31\n");
    sin_riscv_sin_q31();
    printf("PASS benchmark/FastMathFunctions/sin_riscv_sin_q31 count=%d\n", 1);
    return 0;
}
