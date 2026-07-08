#include <stdio.h>
extern void cmplx_mag_riscv_cmplx_mag_q15(void);

int main(void)
{
    printf("Start benchmark/ComplexMathFunctions/cmplx_mag_riscv_cmplx_mag_q15\n");
    printf("RUN cmplx_mag_riscv_cmplx_mag_q15\n");
    cmplx_mag_riscv_cmplx_mag_q15();
    printf("PASS benchmark/ComplexMathFunctions/cmplx_mag_riscv_cmplx_mag_q15 count=%d\n", 1);
    return 0;
}
