#include <stdio.h>
extern void f64Toq7_riscv_f64_to_q7(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_f64_to_q7\n");
    printf("RUN f64Toq7_riscv_f64_to_q7\n");
    f64Toq7_riscv_f64_to_q7();
    printf("PASS skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_f64_to_q7 count=%d\n", 1);
    return 0;
}
