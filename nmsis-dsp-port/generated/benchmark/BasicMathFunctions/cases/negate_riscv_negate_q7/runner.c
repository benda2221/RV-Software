#include <stdio.h>
extern void negate_riscv_negate_q7(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/negate_riscv_negate_q7\n");
    printf("RUN negate_riscv_negate_q7\n");
    negate_riscv_negate_q7();
    printf("PASS benchmark/BasicMathFunctions/negate_riscv_negate_q7 count=%d\n", 1);
    return 0;
}
