#include <stdio.h>
extern void add_riscv_add_q7(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/add_riscv_add_q7\n");
    printf("RUN add_riscv_add_q7\n");
    add_riscv_add_q7();
    printf("PASS benchmark/BasicMathFunctions/add_riscv_add_q7 count=%d\n", 1);
    return 0;
}
