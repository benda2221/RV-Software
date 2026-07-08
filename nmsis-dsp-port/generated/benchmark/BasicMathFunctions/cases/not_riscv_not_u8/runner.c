#include <stdio.h>
extern void not_riscv_not_u8(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/not_riscv_not_u8\n");
    printf("RUN not_riscv_not_u8\n");
    not_riscv_not_u8();
    printf("PASS benchmark/BasicMathFunctions/not_riscv_not_u8 count=%d\n", 1);
    return 0;
}
