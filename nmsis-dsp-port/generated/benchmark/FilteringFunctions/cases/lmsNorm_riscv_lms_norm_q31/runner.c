#include <stdio.h>
extern void lmsNorm_riscv_lms_norm_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/lmsNorm_riscv_lms_norm_q31\n");
    printf("RUN lmsNorm_riscv_lms_norm_q31\n");
    lmsNorm_riscv_lms_norm_q31();
    printf("PASS benchmark/FilteringFunctions/lmsNorm_riscv_lms_norm_q31 count=%d\n", 1);
    return 0;
}
