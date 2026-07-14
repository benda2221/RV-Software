#include <stdio.h>
extern void lmsNorm_riscv_lms_norm_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/lmsNorm_riscv_lms_norm_f32\n");
    printf("RUN lmsNorm_riscv_lms_norm_f32\n");
    lmsNorm_riscv_lms_norm_f32();
    printf("PASS benchmark/FilteringFunctions/lmsNorm_riscv_lms_norm_f32 count=%d\n", 1);
    return 0;
}
