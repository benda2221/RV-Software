#include <stdio.h>
extern void q7ToQ31_riscv_q7_to_q31(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q7ToQ31_riscv_q7_to_q31\n");
    printf("RUN q7ToQ31_riscv_q7_to_q31\n");
    q7ToQ31_riscv_q7_to_q31();
    printf("PASS benchmark/SupportFunctions/q7ToQ31_riscv_q7_to_q31 count=%d\n", 1);
    return 0;
}
