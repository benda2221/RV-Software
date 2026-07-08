#include <stdio.h>
extern void absminNoIdx_riscv_absmin_no_idx_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absminNoIdx_riscv_absmin_no_idx_q15\n");
    printf("RUN absminNoIdx_riscv_absmin_no_idx_q15\n");
    absminNoIdx_riscv_absmin_no_idx_q15();
    printf("PASS benchmark/StatisticsFunctions/absminNoIdx_riscv_absmin_no_idx_q15 count=%d\n", 1);
    return 0;
}
