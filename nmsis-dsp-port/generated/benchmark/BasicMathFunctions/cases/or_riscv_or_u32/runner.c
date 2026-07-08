#include <stdio.h>
extern void or_riscv_or_u32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/or_riscv_or_u32\n");
    printf("RUN or_riscv_or_u32\n");
    or_riscv_or_u32();
    printf("PASS benchmark/BasicMathFunctions/or_riscv_or_u32 count=%d\n", 1);
    return 0;
}
