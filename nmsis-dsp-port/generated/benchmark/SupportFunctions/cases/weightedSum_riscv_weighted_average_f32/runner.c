#include <stdio.h>
extern void weightedSum_riscv_weighted_average_f32(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/weightedSum_riscv_weighted_average_f32\n");
    printf("RUN weightedSum_riscv_weighted_average_f32\n");
    weightedSum_riscv_weighted_average_f32();
    printf("PASS benchmark/SupportFunctions/weightedSum_riscv_weighted_average_f32 count=%d\n", 1);
    return 0;
}
