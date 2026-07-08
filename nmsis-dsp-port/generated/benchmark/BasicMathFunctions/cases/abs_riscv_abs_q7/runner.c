#include <stdio.h>
extern void abs_riscv_abs_q7(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/abs_riscv_abs_q7\n");
    printf("RUN abs_riscv_abs_q7\n");
    abs_riscv_abs_q7();
    printf("PASS benchmark/BasicMathFunctions/abs_riscv_abs_q7 count=%d\n", 1);
    return 0;
}
