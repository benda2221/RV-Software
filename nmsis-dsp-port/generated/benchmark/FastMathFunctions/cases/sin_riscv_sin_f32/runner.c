#include <stdio.h>
extern void sin_riscv_sin_f32(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/sin_riscv_sin_f32\n");
    printf("RUN sin_riscv_sin_f32\n");
    sin_riscv_sin_f32();
    printf("PASS benchmark/FastMathFunctions/sin_riscv_sin_f32 count=%d\n", 1);
    return 0;
}
