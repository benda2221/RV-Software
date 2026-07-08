#include <stdio.h>
extern void maxNoIdx_riscv_max_no_idx_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/maxNoIdx_riscv_max_no_idx_q15\n");
    printf("RUN maxNoIdx_riscv_max_no_idx_q15\n");
    maxNoIdx_riscv_max_no_idx_q15();
    printf("PASS benchmark/StatisticsFunctions/maxNoIdx_riscv_max_no_idx_q15 count=%d\n", 1);
    return 0;
}
