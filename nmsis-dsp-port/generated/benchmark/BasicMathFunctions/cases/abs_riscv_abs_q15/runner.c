#include <stdio.h>
extern void abs_riscv_abs_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/abs_riscv_abs_q15\n");
    printf("RUN abs_riscv_abs_q15\n");
    abs_riscv_abs_q15();
    printf("PASS benchmark/BasicMathFunctions/abs_riscv_abs_q15 count=%d\n", 1);
    return 0;
}
