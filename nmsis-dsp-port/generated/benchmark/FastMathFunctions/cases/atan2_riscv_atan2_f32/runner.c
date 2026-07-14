#include <stdio.h>
extern void atan2_riscv_atan2_f32(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/atan2_riscv_atan2_f32\n");
    printf("RUN atan2_riscv_atan2_f32\n");
    atan2_riscv_atan2_f32();
    printf("PASS benchmark/FastMathFunctions/atan2_riscv_atan2_f32 count=%d\n", 1);
    return 0;
}
