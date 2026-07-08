#include <stdio.h>
extern void and_riscv_and_u8(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/and_riscv_and_u8\n");
    printf("RUN and_riscv_and_u8\n");
    and_riscv_and_u8();
    printf("PASS benchmark/BasicMathFunctions/and_riscv_and_u8 count=%d\n", 1);
    return 0;
}
