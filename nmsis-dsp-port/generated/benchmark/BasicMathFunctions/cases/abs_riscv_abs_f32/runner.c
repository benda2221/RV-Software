#include <stdio.h>
extern void abs_riscv_abs_f32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/abs_riscv_abs_f32\n");
    printf("RUN abs_riscv_abs_f32\n");
    abs_riscv_abs_f32();
    printf("PASS benchmark/BasicMathFunctions/abs_riscv_abs_f32 count=%d\n", 1);
    return 0;
}
