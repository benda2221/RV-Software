#include <stdio.h>
extern void q31ToQ15_riscv_q31_to_q15(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q31ToQ15_riscv_q31_to_q15\n");
    printf("RUN q31ToQ15_riscv_q31_to_q15\n");
    q31ToQ15_riscv_q31_to_q15();
    printf("PASS benchmark/SupportFunctions/q31ToQ15_riscv_q31_to_q15 count=%d\n", 1);
    return 0;
}
