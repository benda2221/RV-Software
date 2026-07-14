#include <stdio.h>
extern void atan2_riscv_atan2_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FastMathFunctions__vendor__NMSIS__DSP__Benchmark__FastMathFunctions__test_riscv_atan2_f16\n");
    printf("RUN atan2_riscv_atan2_f16\n");
    atan2_riscv_atan2_f16();
    printf("PASS skipped-probe/benchmark__FastMathFunctions__vendor__NMSIS__DSP__Benchmark__FastMathFunctions__test_riscv_atan2_f16 count=%d\n", 1);
    return 0;
}
