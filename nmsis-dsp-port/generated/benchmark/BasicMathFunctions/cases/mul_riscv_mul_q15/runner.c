#include <stdio.h>
extern void mul_riscv_mul_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/mul_riscv_mul_q15\n");
    printf("RUN mul_riscv_mul_q15\n");
    mul_riscv_mul_q15();
    printf("PASS benchmark/BasicMathFunctions/mul_riscv_mul_q15 count=%d\n", 1);
    return 0;
}
