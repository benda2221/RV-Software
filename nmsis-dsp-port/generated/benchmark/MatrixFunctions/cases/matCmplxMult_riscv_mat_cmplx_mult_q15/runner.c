#include <stdio.h>
extern void matCmplxMult_riscv_mat_cmplx_mult_q15(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matCmplxMult_riscv_mat_cmplx_mult_q15\n");
    printf("RUN matCmplxMult_riscv_mat_cmplx_mult_q15\n");
    matCmplxMult_riscv_mat_cmplx_mult_q15();
    printf("PASS benchmark/MatrixFunctions/matCmplxMult_riscv_mat_cmplx_mult_q15 count=%d\n", 1);
    return 0;
}
