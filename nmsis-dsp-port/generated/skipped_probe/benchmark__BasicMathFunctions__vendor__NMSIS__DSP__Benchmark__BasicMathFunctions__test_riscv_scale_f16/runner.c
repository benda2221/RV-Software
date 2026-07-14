#include <stdio.h>
extern void scale_riscv_scale_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__BasicMathFunctions__vendor__NMSIS__DSP__Benchmark__BasicMathFunctions__test_riscv_scale_f16\n");
    printf("RUN scale_riscv_scale_f16\n");
    scale_riscv_scale_f16();
    printf("PASS skipped-probe/benchmark__BasicMathFunctions__vendor__NMSIS__DSP__Benchmark__BasicMathFunctions__test_riscv_scale_f16 count=%d\n", 1);
    return 0;
}
