#include <stdio.h>
extern void abs_riscv_abs_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/abs_riscv_abs_q31\n");
    printf("RUN abs_riscv_abs_q31\n");
    abs_riscv_abs_q31();
    printf("PASS benchmark/BasicMathFunctions/abs_riscv_abs_q31 count=%d\n", 1);
    return 0;
}
