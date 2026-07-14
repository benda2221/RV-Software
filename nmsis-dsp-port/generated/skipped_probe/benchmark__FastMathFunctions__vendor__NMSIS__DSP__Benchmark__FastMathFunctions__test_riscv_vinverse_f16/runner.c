#include <stdio.h>
extern void vinverse_riscv_vinverse_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FastMathFunctions__vendor__NMSIS__DSP__Benchmark__FastMathFunctions__test_riscv_vinverse_f16\n");
    printf("RUN vinverse_riscv_vinverse_f16\n");
    vinverse_riscv_vinverse_f16();
    printf("PASS skipped-probe/benchmark__FastMathFunctions__vendor__NMSIS__DSP__Benchmark__FastMathFunctions__test_riscv_vinverse_f16 count=%d\n", 1);
    return 0;
}
