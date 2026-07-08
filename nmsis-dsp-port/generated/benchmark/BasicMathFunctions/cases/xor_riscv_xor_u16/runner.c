#include <stdio.h>
extern void xor_riscv_xor_u16(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/xor_riscv_xor_u16\n");
    printf("RUN xor_riscv_xor_u16\n");
    xor_riscv_xor_u16();
    printf("PASS benchmark/BasicMathFunctions/xor_riscv_xor_u16 count=%d\n", 1);
    return 0;
}
