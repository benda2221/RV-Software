#include <stdio.h>
extern void bilinear_riscv_bilinear_interp_q15(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions/bilinear_riscv_bilinear_interp_q15\n");
    printf("RUN bilinear_riscv_bilinear_interp_q15\n");
    bilinear_riscv_bilinear_interp_q15();
    printf("PASS benchmark/InterpolationFunctions/bilinear_riscv_bilinear_interp_q15 count=%d\n", 1);
    return 0;
}
