#include <stdio.h>
extern void correlate_riscv_correlate_fast_opt_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/correlate_riscv_correlate_fast_opt_q15\n");
    printf("RUN correlate_riscv_correlate_fast_opt_q15\n");
    correlate_riscv_correlate_fast_opt_q15();
    printf("PASS benchmark/FilteringFunctions/correlate_riscv_correlate_fast_opt_q15 count=%d\n", 1);
    return 0;
}
