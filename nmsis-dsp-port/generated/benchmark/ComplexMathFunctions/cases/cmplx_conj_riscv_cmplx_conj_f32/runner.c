#include <stdio.h>
extern void cmplx_conj_riscv_cmplx_conj_f32(void);

int main(void)
{
    printf("Start benchmark/ComplexMathFunctions/cmplx_conj_riscv_cmplx_conj_f32\n");
    printf("RUN cmplx_conj_riscv_cmplx_conj_f32\n");
    cmplx_conj_riscv_cmplx_conj_f32();
    printf("PASS benchmark/ComplexMathFunctions/cmplx_conj_riscv_cmplx_conj_f32 count=%d\n", 1);
    return 0;
}
