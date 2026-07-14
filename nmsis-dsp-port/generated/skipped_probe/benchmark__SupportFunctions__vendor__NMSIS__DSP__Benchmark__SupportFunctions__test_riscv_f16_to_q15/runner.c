#include <stdio.h>
extern void f16ToQ15_riscv_f16_to_q15(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_f16_to_q15\n");
    printf("RUN f16ToQ15_riscv_f16_to_q15\n");
    f16ToQ15_riscv_f16_to_q15();
    printf("PASS skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_f16_to_q15 count=%d\n", 1);
    return 0;
}
