#include <stdio.h>
extern void q15ToQ31_riscv_q15_to_q31(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q15ToQ31_riscv_q15_to_q31\n");
    printf("RUN q15ToQ31_riscv_q15_to_q31\n");
    q15ToQ31_riscv_q15_to_q31();
    printf("PASS benchmark/SupportFunctions/q15ToQ31_riscv_q15_to_q31 count=%d\n", 1);
    return 0;
}
