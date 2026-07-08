#include <stdio.h>
extern void firInterpolate_riscv_fir_interpolate_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firInterpolate_riscv_fir_interpolate_q15\n");
    printf("RUN firInterpolate_riscv_fir_interpolate_q15\n");
    firInterpolate_riscv_fir_interpolate_q15();
    printf("PASS benchmark/FilteringFunctions/firInterpolate_riscv_fir_interpolate_q15 count=%d\n", 1);
    return 0;
}
