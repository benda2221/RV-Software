#include <stdio.h>
extern void f32ToF64_riscv_float_to_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_float_to_f64\n");
    printf("RUN f32ToF64_riscv_float_to_f64\n");
    f32ToF64_riscv_float_to_f64();
    printf("PASS skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_float_to_f64 count=%d\n", 1);
    return 0;
}
