#include <stdio.h>
extern void absminNoIdx_riscv_absmin_no_idx_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/absminNoIdx_riscv_absmin_no_idx_f32\n");
    printf("RUN absminNoIdx_riscv_absmin_no_idx_f32\n");
    absminNoIdx_riscv_absmin_no_idx_f32();
    printf("PASS benchmark/StatisticsFunctions/absminNoIdx_riscv_absmin_no_idx_f32 count=%d\n", 1);
    return 0;
}
