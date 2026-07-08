#include <stdio.h>
extern void cos_riscv_cos_q15(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/cos_riscv_cos_q15\n");
    printf("RUN cos_riscv_cos_q15\n");
    cos_riscv_cos_q15();
    printf("PASS benchmark/FastMathFunctions/cos_riscv_cos_q15 count=%d\n", 1);
    return 0;
}
