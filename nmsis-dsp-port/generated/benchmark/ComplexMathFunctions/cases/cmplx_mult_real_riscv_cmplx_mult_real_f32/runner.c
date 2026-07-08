#include <stdio.h>
extern void cmplx_mult_real_riscv_cmplx_mult_real_f32(void);

int main(void)
{
    printf("Start benchmark/ComplexMathFunctions/cmplx_mult_real_riscv_cmplx_mult_real_f32\n");
    printf("RUN cmplx_mult_real_riscv_cmplx_mult_real_f32\n");
    cmplx_mult_real_riscv_cmplx_mult_real_f32();
    printf("PASS benchmark/ComplexMathFunctions/cmplx_mult_real_riscv_cmplx_mult_real_f32 count=%d\n", 1);
    return 0;
}
