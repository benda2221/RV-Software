#include <stdio.h>
extern void q7ToQ15_riscv_q7_to_q15(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q7ToQ15_riscv_q7_to_q15\n");
    printf("RUN q7ToQ15_riscv_q7_to_q15\n");
    q7ToQ15_riscv_q7_to_q15();
    printf("PASS benchmark/SupportFunctions/q7ToQ15_riscv_q7_to_q15 count=%d\n", 1);
    return 0;
}
