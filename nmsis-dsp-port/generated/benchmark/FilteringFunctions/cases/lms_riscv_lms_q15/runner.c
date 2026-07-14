#include <stdio.h>
extern void lms_riscv_lms_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/lms_riscv_lms_q15\n");
    printf("RUN lms_riscv_lms_q15\n");
    lms_riscv_lms_q15();
    printf("PASS benchmark/FilteringFunctions/lms_riscv_lms_q15 count=%d\n", 1);
    return 0;
}
