#include <stdio.h>
extern void absminNoIdx_riscv_absmin_no_idx_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absminNoIdx_riscv_absmin_no_idx_q31\n");
    printf("RUN absminNoIdx_riscv_absmin_no_idx_q31\n");
    absminNoIdx_riscv_absmin_no_idx_q31();
    printf("PASS benchmark/StatisticsFunctions/absminNoIdx_riscv_absmin_no_idx_q31 count=%d\n", 1);
    return 0;
}
