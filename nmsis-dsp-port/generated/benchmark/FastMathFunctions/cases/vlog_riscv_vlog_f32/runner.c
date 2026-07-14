#include <stdio.h>
extern void vlog_riscv_vlog_f32(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/vlog_riscv_vlog_f32\n");
    printf("RUN vlog_riscv_vlog_f32\n");
    vlog_riscv_vlog_f32();
    printf("PASS benchmark/FastMathFunctions/vlog_riscv_vlog_f32 count=%d\n", 1);
    return 0;
}
