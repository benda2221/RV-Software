#include <stdio.h>
extern void maxNoIdx_riscv_max_no_idx_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/maxNoIdx_riscv_max_no_idx_q31\n");
    printf("RUN maxNoIdx_riscv_max_no_idx_q31\n");
    maxNoIdx_riscv_max_no_idx_q31();
    printf("PASS benchmark/StatisticsFunctions/maxNoIdx_riscv_max_no_idx_q31 count=%d\n", 1);
    return 0;
}
