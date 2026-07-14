#include <stdio.h>
extern void df2T_riscv_biquad_cascade_df2T_f64(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_biquad_cascade_df2T_f64\n");
    printf("RUN df2T_riscv_biquad_cascade_df2T_f64\n");
    df2T_riscv_biquad_cascade_df2T_f64();
    printf("PASS skipped-probe/benchmark__FilteringFunctions__vendor__NMSIS__DSP__Benchmark__FilteringFunctions__test_riscv_biquad_cascade_df2T_f64 count=%d\n", 1);
    return 0;
}
