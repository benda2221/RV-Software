#include <stdio.h>
extern void df1_riscv_biquad_cascade_df1_fast_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/df1_riscv_biquad_cascade_df1_fast_q15\n");
    printf("RUN df1_riscv_biquad_cascade_df1_fast_q15\n");
    df1_riscv_biquad_cascade_df1_fast_q15();
    printf("PASS benchmark/FilteringFunctions/df1_riscv_biquad_cascade_df1_fast_q15 count=%d\n", 1);
    return 0;
}
