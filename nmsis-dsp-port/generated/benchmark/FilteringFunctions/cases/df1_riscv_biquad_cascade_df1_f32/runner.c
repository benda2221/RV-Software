#include <stdio.h>
extern void df1_riscv_biquad_cascade_df1_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/df1_riscv_biquad_cascade_df1_f32\n");
    printf("RUN df1_riscv_biquad_cascade_df1_f32\n");
    df1_riscv_biquad_cascade_df1_f32();
    printf("PASS benchmark/FilteringFunctions/df1_riscv_biquad_cascade_df1_f32 count=%d\n", 1);
    return 0;
}
