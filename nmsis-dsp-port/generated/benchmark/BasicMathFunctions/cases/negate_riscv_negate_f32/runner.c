#include <stdio.h>
extern void negate_riscv_negate_f32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/negate_riscv_negate_f32\n");
    printf("RUN negate_riscv_negate_f32\n");
    negate_riscv_negate_f32();
    printf("PASS benchmark/BasicMathFunctions/negate_riscv_negate_f32 count=%d\n", 1);
    return 0;
}
