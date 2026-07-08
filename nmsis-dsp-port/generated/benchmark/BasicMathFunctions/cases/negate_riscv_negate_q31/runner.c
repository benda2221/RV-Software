#include <stdio.h>
extern void negate_riscv_negate_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/negate_riscv_negate_q31\n");
    printf("RUN negate_riscv_negate_q31\n");
    negate_riscv_negate_q31();
    printf("PASS benchmark/BasicMathFunctions/negate_riscv_negate_q31 count=%d\n", 1);
    return 0;
}
