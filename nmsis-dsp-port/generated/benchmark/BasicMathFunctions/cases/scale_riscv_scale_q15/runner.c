#include <stdio.h>
extern void scale_riscv_scale_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/scale_riscv_scale_q15\n");
    printf("RUN scale_riscv_scale_q15\n");
    scale_riscv_scale_q15();
    printf("PASS benchmark/BasicMathFunctions/scale_riscv_scale_q15 count=%d\n", 1);
    return 0;
}
