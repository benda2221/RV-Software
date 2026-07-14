#include <stdio.h>
extern void correlate_riscv_correlate_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/correlate_riscv_correlate_f32\n");
    printf("RUN correlate_riscv_correlate_f32\n");
    correlate_riscv_correlate_f32();
    printf("PASS benchmark/FilteringFunctions/correlate_riscv_correlate_f32 count=%d\n", 1);
    return 0;
}
