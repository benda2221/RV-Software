#include <stdio.h>
extern void bilinear_riscv_bilinear_interp_f32(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions/bilinear_riscv_bilinear_interp_f32\n");
    printf("RUN bilinear_riscv_bilinear_interp_f32\n");
    bilinear_riscv_bilinear_interp_f32();
    printf("PASS benchmark/InterpolationFunctions/bilinear_riscv_bilinear_interp_f32 count=%d\n", 1);
    return 0;
}
