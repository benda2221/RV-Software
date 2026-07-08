#include <stdio.h>
extern void not_riscv_not_u16(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/not_riscv_not_u16\n");
    printf("RUN not_riscv_not_u16\n");
    not_riscv_not_u16();
    printf("PASS benchmark/BasicMathFunctions/not_riscv_not_u16 count=%d\n", 1);
    return 0;
}
