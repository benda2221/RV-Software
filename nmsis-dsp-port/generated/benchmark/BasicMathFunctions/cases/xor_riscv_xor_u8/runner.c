#include <stdio.h>
extern void xor_riscv_xor_u8(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/xor_riscv_xor_u8\n");
    printf("RUN xor_riscv_xor_u8\n");
    xor_riscv_xor_u8();
    printf("PASS benchmark/BasicMathFunctions/xor_riscv_xor_u8 count=%d\n", 1);
    return 0;
}
