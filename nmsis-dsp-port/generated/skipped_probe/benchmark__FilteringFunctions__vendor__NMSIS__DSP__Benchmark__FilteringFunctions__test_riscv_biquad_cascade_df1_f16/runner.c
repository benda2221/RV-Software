#include <stdio.h>
extern void df1_riscv_biquad_cascade_df1_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_biquad_cascade_df1_f16\n");
    printf("RUN df1_riscv_biquad_cascade_df1_f16\n");
    df1_riscv_biquad_cascade_df1_f16();
    printf("PASS skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_biquad_cascade_df1_f16 count=%d\n", 1);
    return 0;
}
