#include <stdio.h>
extern void lms_riscv_lms_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/lms_riscv_lms_q31\n");
    printf("RUN lms_riscv_lms_q31\n");
    lms_riscv_lms_q31();
    printf("PASS benchmark/FilteringFunctions/lms_riscv_lms_q31 count=%d\n", 1);
    return 0;
}
