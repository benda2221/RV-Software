#include <stdio.h>
extern void absmaxNoIdx_riscv_absmax_no_idx_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absmaxNoIdx_riscv_absmax_no_idx_q15\n");
    printf("RUN absmaxNoIdx_riscv_absmax_no_idx_q15\n");
    absmaxNoIdx_riscv_absmax_no_idx_q15();
    printf("PASS benchmark/StatisticsFunctions/absmaxNoIdx_riscv_absmax_no_idx_q15 count=%d\n", 1);
    return 0;
}
