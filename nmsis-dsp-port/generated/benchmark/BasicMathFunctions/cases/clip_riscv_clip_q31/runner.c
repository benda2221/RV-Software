#include <stdio.h>
extern void clip_riscv_clip_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/clip_riscv_clip_q31\n");
    printf("RUN clip_riscv_clip_q31\n");
    clip_riscv_clip_q31();
    printf("PASS benchmark/BasicMathFunctions/clip_riscv_clip_q31 count=%d\n", 1);
    return 0;
}
