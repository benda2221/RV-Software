#include <stdio.h>
extern void scale_riscv_scale_f32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/scale_riscv_scale_f32\n");
    printf("RUN scale_riscv_scale_f32\n");
    scale_riscv_scale_f32();
    printf("PASS benchmark/BasicMathFunctions/scale_riscv_scale_f32 count=%d\n", 1);
    return 0;
}
