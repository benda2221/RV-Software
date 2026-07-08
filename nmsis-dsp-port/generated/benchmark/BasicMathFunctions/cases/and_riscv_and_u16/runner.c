#include <stdio.h>
extern void and_riscv_and_u16(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/and_riscv_and_u16\n");
    printf("RUN and_riscv_and_u16\n");
    and_riscv_and_u16();
    printf("PASS benchmark/BasicMathFunctions/and_riscv_and_u16 count=%d\n", 1);
    return 0;
}
