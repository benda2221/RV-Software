#include <stdio.h>
extern void correlate_riscv_correlate_opt_q7(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/correlate_riscv_correlate_opt_q7\n");
    printf("RUN correlate_riscv_correlate_opt_q7\n");
    correlate_riscv_correlate_opt_q7();
    printf("PASS benchmark/FilteringFunctions/correlate_riscv_correlate_opt_q7 count=%d\n", 1);
    return 0;
}
