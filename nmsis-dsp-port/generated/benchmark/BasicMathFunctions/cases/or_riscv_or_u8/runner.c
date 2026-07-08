#include <stdio.h>
extern void or_riscv_or_u8(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/or_riscv_or_u8\n");
    printf("RUN or_riscv_or_u8\n");
    or_riscv_or_u8();
    printf("PASS benchmark/BasicMathFunctions/or_riscv_or_u8 count=%d\n", 1);
    return 0;
}
