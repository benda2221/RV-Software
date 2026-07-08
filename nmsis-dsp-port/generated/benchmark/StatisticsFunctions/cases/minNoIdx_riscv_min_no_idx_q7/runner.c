#include <stdio.h>
extern void minNoIdx_riscv_min_no_idx_q7(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/minNoIdx_riscv_min_no_idx_q7\n");
    printf("RUN minNoIdx_riscv_min_no_idx_q7\n");
    minNoIdx_riscv_min_no_idx_q7();
    printf("PASS benchmark/StatisticsFunctions/minNoIdx_riscv_min_no_idx_q7 count=%d\n", 1);
    return 0;
}
