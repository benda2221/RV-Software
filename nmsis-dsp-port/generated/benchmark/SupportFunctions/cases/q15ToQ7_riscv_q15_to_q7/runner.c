#include <stdio.h>
extern void q15ToQ7_riscv_q15_to_q7(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q15ToQ7_riscv_q15_to_q7\n");
    printf("RUN q15ToQ7_riscv_q15_to_q7\n");
    q15ToQ7_riscv_q15_to_q7();
    printf("PASS benchmark/SupportFunctions/q15ToQ7_riscv_q15_to_q7 count=%d\n", 1);
    return 0;
}
