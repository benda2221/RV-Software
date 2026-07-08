#include <stdio.h>
extern void add_riscv_add_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/add_riscv_add_q15\n");
    printf("RUN add_riscv_add_q15\n");
    add_riscv_add_q15();
    printf("PASS benchmark/BasicMathFunctions/add_riscv_add_q15 count=%d\n", 1);
    return 0;
}
