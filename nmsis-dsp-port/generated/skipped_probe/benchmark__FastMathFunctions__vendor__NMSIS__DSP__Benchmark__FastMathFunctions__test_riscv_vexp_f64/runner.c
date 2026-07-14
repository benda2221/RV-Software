#include <stdio.h>
extern void vexp_riscv_vexp_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FastMathFunctions__vendor__NMSIS__DSP__Benchmark__FastMathFunctions__test_riscv_vexp_f64\n");
    printf("RUN vexp_riscv_vexp_f64\n");
    vexp_riscv_vexp_f64();
    printf("PASS skipped-probe/benchmark__FastMathFunctions__vendor__NMSIS__DSP__Benchmark__FastMathFunctions__test_riscv_vexp_f64 count=%d\n", 1);
    return 0;
}
