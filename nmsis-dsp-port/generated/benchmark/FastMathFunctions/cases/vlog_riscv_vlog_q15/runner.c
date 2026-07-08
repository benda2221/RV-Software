#include <stdio.h>
extern void vlog_riscv_vlog_q15(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/vlog_riscv_vlog_q15\n");
    printf("RUN vlog_riscv_vlog_q15\n");
    vlog_riscv_vlog_q15();
    printf("PASS benchmark/FastMathFunctions/vlog_riscv_vlog_q15 count=%d\n", 1);
    return 0;
}
