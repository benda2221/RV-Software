#include <stdio.h>
extern void cmplx_mag_riscv_cmplx_mag_q31(void);

int main(void)
{
    printf("Start benchmark/ComplexMathFunctions/cmplx_mag_riscv_cmplx_mag_q31\n");
    printf("RUN cmplx_mag_riscv_cmplx_mag_q31\n");
    cmplx_mag_riscv_cmplx_mag_q31();
    printf("PASS benchmark/ComplexMathFunctions/cmplx_mag_riscv_cmplx_mag_q31 count=%d\n", 1);
    return 0;
}
