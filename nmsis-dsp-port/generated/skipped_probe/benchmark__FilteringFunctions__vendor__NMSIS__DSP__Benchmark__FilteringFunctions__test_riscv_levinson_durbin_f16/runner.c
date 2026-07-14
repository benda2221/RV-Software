#include <stdio.h>
extern void levinsonDurbin_riscv_levinson_durbin_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_levinson_durbin_f16\n");
    printf("RUN levinsonDurbin_riscv_levinson_durbin_f16\n");
    levinsonDurbin_riscv_levinson_durbin_f16();
    printf("PASS skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_levinson_durbin_f16 count=%d\n", 1);
    return 0;
}
