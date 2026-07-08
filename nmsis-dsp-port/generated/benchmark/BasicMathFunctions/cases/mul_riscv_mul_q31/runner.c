#include <stdio.h>
extern void mul_riscv_mul_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/mul_riscv_mul_q31\n");
    printf("RUN mul_riscv_mul_q31\n");
    mul_riscv_mul_q31();
    printf("PASS benchmark/BasicMathFunctions/mul_riscv_mul_q31 count=%d\n", 1);
    return 0;
}
