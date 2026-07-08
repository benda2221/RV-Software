#include <stdio.h>
extern void not_riscv_not_u32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/not_riscv_not_u32\n");
    printf("RUN not_riscv_not_u32\n");
    not_riscv_not_u32();
    printf("PASS benchmark/BasicMathFunctions/not_riscv_not_u32 count=%d\n", 1);
    return 0;
}
