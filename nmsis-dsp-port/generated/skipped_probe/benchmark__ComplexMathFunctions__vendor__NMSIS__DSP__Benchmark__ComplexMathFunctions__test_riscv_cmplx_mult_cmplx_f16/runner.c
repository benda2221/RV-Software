#include <stdio.h>
extern void cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__ComplexMathFunctions__vendor__NMSIS__DSP__Benchmark__ComplexMathFunctions__test_riscv_cmplx_mult_cmplx_f16\n");
    printf("RUN cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_f16\n");
    cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_f16();
    printf("PASS skipped-probe/benchmark__ComplexMathFunctions__vendor__NMSIS__DSP__Benchmark__ComplexMathFunctions__test_riscv_cmplx_mult_cmplx_f16 count=%d\n", 1);
    return 0;
}
