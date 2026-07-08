#include <stdio.h>
extern void df2T_riscv_biquad_cascade_stereo_df2T_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/df2T_riscv_biquad_cascade_stereo_df2T_f32\n");
    printf("RUN df2T_riscv_biquad_cascade_stereo_df2T_f32\n");
    df2T_riscv_biquad_cascade_stereo_df2T_f32();
    printf("PASS benchmark/FilteringFunctions/df2T_riscv_biquad_cascade_stereo_df2T_f32 count=%d\n", 1);
    return 0;
}
