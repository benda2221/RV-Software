#include <stdio.h>
extern void dot_prod_riscv_dot_prod_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__BasicMathFunctions__vendor__NMSIS__DSP__Benchmark__BasicMathFunctions__test_riscv_dot_prod_f16\n");
    printf("RUN dot_prod_riscv_dot_prod_f16\n");
    dot_prod_riscv_dot_prod_f16();
    printf("PASS skipped-probe/benchmark__BasicMathFunctions__vendor__NMSIS__DSP__Benchmark__BasicMathFunctions__test_riscv_dot_prod_f16 count=%d\n", 1);
    return 0;
}
