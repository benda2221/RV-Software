#include <stdio.h>
extern void f64Toq31_riscv_f64_to_q31(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_f64_to_q31\n");
    printf("RUN f64Toq31_riscv_f64_to_q31\n");
    f64Toq31_riscv_f64_to_q31();
    printf("PASS skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_f64_to_q31 count=%d\n", 1);
    return 0;
}
