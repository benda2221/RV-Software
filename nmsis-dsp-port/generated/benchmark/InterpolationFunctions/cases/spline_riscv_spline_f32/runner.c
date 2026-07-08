#include <stdio.h>
extern void spline_riscv_spline_f32(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions/spline_riscv_spline_f32\n");
    printf("RUN spline_riscv_spline_f32\n");
    spline_riscv_spline_f32();
    printf("PASS benchmark/InterpolationFunctions/spline_riscv_spline_f32 count=%d\n", 1);
    return 0;
}
