#include <stdio.h>
extern void df1_riscv_biquad_cascade_df1_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/df1_riscv_biquad_cascade_df1_q31\n");
    printf("RUN df1_riscv_biquad_cascade_df1_q31\n");
    df1_riscv_biquad_cascade_df1_q31();
    printf("PASS benchmark/FilteringFunctions/df1_riscv_biquad_cascade_df1_q31 count=%d\n", 1);
    return 0;
}
