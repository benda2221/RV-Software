#include <stdio.h>
extern void scale_riscv_scale_q7(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/scale_riscv_scale_q7\n");
    printf("RUN scale_riscv_scale_q7\n");
    scale_riscv_scale_q7();
    printf("PASS benchmark/BasicMathFunctions/scale_riscv_scale_q7 count=%d\n", 1);
    return 0;
}
