#include <stdio.h>
extern void sub_riscv_sub_f32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/sub_riscv_sub_f32\n");
    printf("RUN sub_riscv_sub_f32\n");
    sub_riscv_sub_f32();
    printf("PASS benchmark/BasicMathFunctions/sub_riscv_sub_f32 count=%d\n", 1);
    return 0;
}
