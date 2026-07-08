#include <stdio.h>
extern void clip_riscv_clip_f32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/clip_riscv_clip_f32\n");
    printf("RUN clip_riscv_clip_f32\n");
    clip_riscv_clip_f32();
    printf("PASS benchmark/BasicMathFunctions/clip_riscv_clip_f32 count=%d\n", 1);
    return 0;
}
