#include <stdio.h>
extern void f32ToF16_riscv_float_to_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_float_to_f16\n");
    printf("RUN f32ToF16_riscv_float_to_f16\n");
    f32ToF16_riscv_float_to_f16();
    printf("PASS skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_float_to_f16 count=%d\n", 1);
    return 0;
}
