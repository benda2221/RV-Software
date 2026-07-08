#include <stdio.h>
extern void offset_riscv_offset_f32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/offset_riscv_offset_f32\n");
    printf("RUN offset_riscv_offset_f32\n");
    offset_riscv_offset_f32();
    printf("PASS benchmark/BasicMathFunctions/offset_riscv_offset_f32 count=%d\n", 1);
    return 0;
}
