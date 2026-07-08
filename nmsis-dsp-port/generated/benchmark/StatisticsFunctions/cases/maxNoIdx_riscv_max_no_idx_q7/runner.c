#include <stdio.h>
extern void maxNoIdx_riscv_max_no_idx_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/maxNoIdx_riscv_max_no_idx_q7\n");
    printf("RUN maxNoIdx_riscv_max_no_idx_q7\n");
    maxNoIdx_riscv_max_no_idx_q7();
    printf("PASS benchmark/StatisticsFunctions/maxNoIdx_riscv_max_no_idx_q7 count=%d\n", 1);
    return 0;
}
