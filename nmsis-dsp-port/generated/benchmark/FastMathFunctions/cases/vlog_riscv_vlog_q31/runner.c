#include <stdio.h>
extern void vlog_riscv_vlog_q31(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/vlog_riscv_vlog_q31\n");
    printf("RUN vlog_riscv_vlog_q31\n");
    vlog_riscv_vlog_q31();
    printf("PASS benchmark/FastMathFunctions/vlog_riscv_vlog_q31 count=%d\n", 1);
    return 0;
}
