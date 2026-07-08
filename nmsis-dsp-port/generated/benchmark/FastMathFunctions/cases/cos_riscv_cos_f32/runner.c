#include <stdio.h>
extern void cos_riscv_cos_f32(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/cos_riscv_cos_f32\n");
    printf("RUN cos_riscv_cos_f32\n");
    cos_riscv_cos_f32();
    printf("PASS benchmark/FastMathFunctions/cos_riscv_cos_f32 count=%d\n", 1);
    return 0;
}
