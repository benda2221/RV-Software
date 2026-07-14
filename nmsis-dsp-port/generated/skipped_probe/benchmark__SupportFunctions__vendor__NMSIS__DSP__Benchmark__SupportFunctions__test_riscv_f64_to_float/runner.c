#include <stdio.h>
extern void f64ToF32_riscv_f64_to_float(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_f64_to_float\n");
    printf("RUN f64ToF32_riscv_f64_to_float\n");
    f64ToF32_riscv_f64_to_float();
    printf("PASS skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_f64_to_float count=%d\n", 1);
    return 0;
}
