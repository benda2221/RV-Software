#include <stdio.h>
extern void cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_q15(void);

int main(void)
{
    printf("Start benchmark/ComplexMathFunctions/cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_q15\n");
    printf("RUN cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_q15\n");
    cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_q15();
    printf("PASS benchmark/ComplexMathFunctions/cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_q15 count=%d\n", 1);
    return 0;
}
