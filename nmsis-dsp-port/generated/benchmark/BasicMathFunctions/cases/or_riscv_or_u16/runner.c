#include <stdio.h>
extern void or_riscv_or_u16(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/or_riscv_or_u16\n");
    printf("RUN or_riscv_or_u16\n");
    or_riscv_or_u16();
    printf("PASS benchmark/BasicMathFunctions/or_riscv_or_u16 count=%d\n", 1);
    return 0;
}
