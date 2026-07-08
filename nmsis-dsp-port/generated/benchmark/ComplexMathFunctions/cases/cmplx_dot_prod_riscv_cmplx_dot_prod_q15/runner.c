#include <stdio.h>
extern void cmplx_dot_prod_riscv_cmplx_dot_prod_q15(void);

int main(void)
{
    printf("Start benchmark/ComplexMathFunctions/cmplx_dot_prod_riscv_cmplx_dot_prod_q15\n");
    printf("RUN cmplx_dot_prod_riscv_cmplx_dot_prod_q15\n");
    cmplx_dot_prod_riscv_cmplx_dot_prod_q15();
    printf("PASS benchmark/ComplexMathFunctions/cmplx_dot_prod_riscv_cmplx_dot_prod_q15 count=%d\n", 1);
    return 0;
}
