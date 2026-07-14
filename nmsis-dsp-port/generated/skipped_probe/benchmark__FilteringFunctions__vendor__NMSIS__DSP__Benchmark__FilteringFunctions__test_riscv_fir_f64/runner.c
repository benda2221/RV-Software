#include <stdio.h>
extern void fir_riscv_fir_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_fir_f64\n");
    printf("RUN fir_riscv_fir_f64\n");
    fir_riscv_fir_f64();
    printf("PASS skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_fir_f64 count=%d\n", 1);
    return 0;
}
