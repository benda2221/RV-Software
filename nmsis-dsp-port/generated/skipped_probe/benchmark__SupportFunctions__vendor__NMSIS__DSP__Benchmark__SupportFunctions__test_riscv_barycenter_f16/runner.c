#include <stdio.h>
extern void barycenter_riscv_barycenter_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_barycenter_f16\n");
    printf("RUN barycenter_riscv_barycenter_f16\n");
    barycenter_riscv_barycenter_f16();
    printf("PASS skipped-probe/benchmark__SupportFunctions__vendor__NMSIS__DSP__Benchmark__SupportFunctions__test_riscv_barycenter_f16 count=%d\n", 1);
    return 0;
}
