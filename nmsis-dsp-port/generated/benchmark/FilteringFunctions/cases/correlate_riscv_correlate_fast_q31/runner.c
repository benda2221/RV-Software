#include <stdio.h>
extern void correlate_riscv_correlate_fast_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/correlate_riscv_correlate_fast_q31\n");
    printf("RUN correlate_riscv_correlate_fast_q31\n");
    correlate_riscv_correlate_fast_q31();
    printf("PASS benchmark/FilteringFunctions/correlate_riscv_correlate_fast_q31 count=%d\n", 1);
    return 0;
}
