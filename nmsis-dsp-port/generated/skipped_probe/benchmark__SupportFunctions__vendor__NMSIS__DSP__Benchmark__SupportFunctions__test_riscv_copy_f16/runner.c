#include <stdio.h>
extern void copy_riscv_copy_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_copy_f16\n");
    printf("RUN copy_riscv_copy_f16\n");
    copy_riscv_copy_f16();
    printf("PASS skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_copy_f16 count=%d\n", 1);
    return 0;
}
