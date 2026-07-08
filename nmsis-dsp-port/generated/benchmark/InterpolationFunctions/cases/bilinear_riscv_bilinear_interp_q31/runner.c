#include <stdio.h>
extern void bilinear_riscv_bilinear_interp_q31(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions/bilinear_riscv_bilinear_interp_q31\n");
    printf("RUN bilinear_riscv_bilinear_interp_q31\n");
    bilinear_riscv_bilinear_interp_q31();
    printf("PASS benchmark/InterpolationFunctions/bilinear_riscv_bilinear_interp_q31 count=%d\n", 1);
    return 0;
}
