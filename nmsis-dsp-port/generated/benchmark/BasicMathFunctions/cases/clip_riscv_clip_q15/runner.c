#include <stdio.h>
extern void clip_riscv_clip_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/clip_riscv_clip_q15\n");
    printf("RUN clip_riscv_clip_q15\n");
    clip_riscv_clip_q15();
    printf("PASS benchmark/BasicMathFunctions/clip_riscv_clip_q15 count=%d\n", 1);
    return 0;
}
