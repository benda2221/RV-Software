#include <stdio.h>
extern void scale_riscv_scale_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/scale_riscv_scale_q31\n");
    printf("RUN scale_riscv_scale_q31\n");
    scale_riscv_scale_q31();
    printf("PASS benchmark/BasicMathFunctions/scale_riscv_scale_q31 count=%d\n", 1);
    return 0;
}
