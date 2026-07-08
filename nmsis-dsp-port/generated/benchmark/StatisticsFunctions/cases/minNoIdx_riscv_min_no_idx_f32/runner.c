#include <stdio.h>
extern void minNoIdx_riscv_min_no_idx_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/minNoIdx_riscv_min_no_idx_f32\n");
    printf("RUN minNoIdx_riscv_min_no_idx_f32\n");
    minNoIdx_riscv_min_no_idx_f32();
    printf("PASS benchmark/StatisticsFunctions/minNoIdx_riscv_min_no_idx_f32 count=%d\n", 1);
    return 0;
}
