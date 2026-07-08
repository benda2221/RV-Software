#include <stdio.h>
extern void linear_riscv_linear_interp_f32(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions/linear_riscv_linear_interp_f32\n");
    printf("RUN linear_riscv_linear_interp_f32\n");
    linear_riscv_linear_interp_f32();
    printf("PASS benchmark/InterpolationFunctions/linear_riscv_linear_interp_f32 count=%d\n", 1);
    return 0;
}
