#include <stdio.h>
extern void q31ToQ7_riscv_q31_to_q7(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q31ToQ7_riscv_q31_to_q7\n");
    printf("RUN q31ToQ7_riscv_q31_to_q7\n");
    q31ToQ7_riscv_q31_to_q7();
    printf("PASS benchmark/SupportFunctions/q31ToQ7_riscv_q31_to_q7 count=%d\n", 1);
    return 0;
}
