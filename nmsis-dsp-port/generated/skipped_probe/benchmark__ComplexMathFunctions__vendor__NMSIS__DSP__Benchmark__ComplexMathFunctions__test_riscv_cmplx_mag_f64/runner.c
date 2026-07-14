#include <stdio.h>
extern void cmplx_mag_riscv_cmplx_mag_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__ComplexMathFunctions__vendor__NMSIS__DSP__Benchmark__ComplexMathFunctions__test_riscv_cmplx_mag_f64\n");
    printf("RUN cmplx_mag_riscv_cmplx_mag_f64\n");
    cmplx_mag_riscv_cmplx_mag_f64();
    printf("PASS skipped-probe/benchmark__ComplexMathFunctions__vendor__NMSIS__DSP__Benchmark__ComplexMathFunctions__test_riscv_cmplx_mag_f64 count=%d\n", 1);
    return 0;
}
