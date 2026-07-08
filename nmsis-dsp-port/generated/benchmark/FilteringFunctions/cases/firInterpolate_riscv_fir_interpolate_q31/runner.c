#include <stdio.h>
extern void firInterpolate_riscv_fir_interpolate_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firInterpolate_riscv_fir_interpolate_q31\n");
    printf("RUN firInterpolate_riscv_fir_interpolate_q31\n");
    firInterpolate_riscv_fir_interpolate_q31();
    printf("PASS benchmark/FilteringFunctions/firInterpolate_riscv_fir_interpolate_q31 count=%d\n", 1);
    return 0;
}
