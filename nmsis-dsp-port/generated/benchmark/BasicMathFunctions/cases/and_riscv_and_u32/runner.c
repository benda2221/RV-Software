#include <stdio.h>
extern void and_riscv_and_u32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/and_riscv_and_u32\n");
    printf("RUN and_riscv_and_u32\n");
    and_riscv_and_u32();
    printf("PASS benchmark/BasicMathFunctions/and_riscv_and_u32 count=%d\n", 1);
    return 0;
}
