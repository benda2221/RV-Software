#include <stdio.h>
extern void sqrt_riscv_sqrt_f32(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/sqrt_riscv_sqrt_f32\n");
    printf("RUN sqrt_riscv_sqrt_f32\n");
    sqrt_riscv_sqrt_f32();
    printf("PASS benchmark/FastMathFunctions/sqrt_riscv_sqrt_f32 count=%d\n", 1);
    return 0;
}
