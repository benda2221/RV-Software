#include <stdio.h>
extern void xor_riscv_xor_u32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/xor_riscv_xor_u32\n");
    printf("RUN xor_riscv_xor_u32\n");
    xor_riscv_xor_u32();
    printf("PASS benchmark/BasicMathFunctions/xor_riscv_xor_u32 count=%d\n", 1);
    return 0;
}
