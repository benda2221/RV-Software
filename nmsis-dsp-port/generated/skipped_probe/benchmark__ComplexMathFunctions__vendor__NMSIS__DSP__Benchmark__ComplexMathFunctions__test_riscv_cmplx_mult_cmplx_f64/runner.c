#include <stdio.h>
extern void cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__ComplexMathFunctions__vendor__NMSIS__DSP__Benchmark__ComplexMathFunctions__test_riscv_cmplx_mult_cmplx_f64\n");
    printf("RUN cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_f64\n");
    cmplx_mult_cmplx_riscv_cmplx_mult_cmplx_f64();
    printf("PASS skipped-probe/benchmark__ComplexMathFunctions__vendor__NMSIS__DSP__Benchmark__ComplexMathFunctions__test_riscv_cmplx_mult_cmplx_f64 count=%d\n", 1);
    return 0;
}
