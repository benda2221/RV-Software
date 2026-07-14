#include <stdio.h>
extern void vlog_riscv_vlog_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FastMathFunctions__vendor__NMSIS__DSP__Benchmark__FastMathFunctions__test_riscv_vlog_f64\n");
    printf("RUN vlog_riscv_vlog_f64\n");
    vlog_riscv_vlog_f64();
    printf("PASS skipped-probe/benchmark__FastMathFunctions__vendor__NMSIS__DSP__Benchmark__FastMathFunctions__test_riscv_vlog_f64 count=%d\n", 1);
    return 0;
}
