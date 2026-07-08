#include <stdio.h>
extern void cos_riscv_cos_q31(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/cos_riscv_cos_q31\n");
    printf("RUN cos_riscv_cos_q31\n");
    cos_riscv_cos_q31();
    printf("PASS benchmark/FastMathFunctions/cos_riscv_cos_q31 count=%d\n", 1);
    return 0;
}
