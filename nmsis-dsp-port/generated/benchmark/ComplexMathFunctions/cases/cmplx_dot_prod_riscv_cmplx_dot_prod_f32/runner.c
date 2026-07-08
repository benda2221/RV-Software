#include <stdio.h>
extern void cmplx_dot_prod_riscv_cmplx_dot_prod_f32(void);

int main(void)
{
    printf("Start benchmark/ComplexMathFunctions/cmplx_dot_prod_riscv_cmplx_dot_prod_f32\n");
    printf("RUN cmplx_dot_prod_riscv_cmplx_dot_prod_f32\n");
    cmplx_dot_prod_riscv_cmplx_dot_prod_f32();
    printf("PASS benchmark/ComplexMathFunctions/cmplx_dot_prod_riscv_cmplx_dot_prod_f32 count=%d\n", 1);
    return 0;
}
