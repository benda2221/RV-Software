#include <stdio.h>
extern void negate_riscv_negate_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/negate_riscv_negate_q15\n");
    printf("RUN negate_riscv_negate_q15\n");
    negate_riscv_negate_q15();
    printf("PASS benchmark/BasicMathFunctions/negate_riscv_negate_q15 count=%d\n", 1);
    return 0;
}
