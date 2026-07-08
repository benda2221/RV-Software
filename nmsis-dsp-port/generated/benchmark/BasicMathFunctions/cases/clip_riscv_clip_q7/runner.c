#include <stdio.h>
extern void clip_riscv_clip_q7(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/clip_riscv_clip_q7\n");
    printf("RUN clip_riscv_clip_q7\n");
    clip_riscv_clip_q7();
    printf("PASS benchmark/BasicMathFunctions/clip_riscv_clip_q7 count=%d\n", 1);
    return 0;
}
