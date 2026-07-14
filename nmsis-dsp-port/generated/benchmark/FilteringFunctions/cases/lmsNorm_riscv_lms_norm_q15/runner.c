#include <stdio.h>
extern void lmsNorm_riscv_lms_norm_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/lmsNorm_riscv_lms_norm_q15\n");
    printf("RUN lmsNorm_riscv_lms_norm_q15\n");
    lmsNorm_riscv_lms_norm_q15();
    printf("PASS benchmark/FilteringFunctions/lmsNorm_riscv_lms_norm_q15 count=%d\n", 1);
    return 0;
}
