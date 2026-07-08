#include <stdio.h>
extern void firInterpolate_riscv_fir_interpolate_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firInterpolate_riscv_fir_interpolate_f32\n");
    printf("RUN firInterpolate_riscv_fir_interpolate_f32\n");
    firInterpolate_riscv_fir_interpolate_f32();
    printf("PASS benchmark/FilteringFunctions/firInterpolate_riscv_fir_interpolate_f32 count=%d\n", 1);
    return 0;
}
