#include <stdio.h>
extern void atan2_riscv_atan2_q15(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/atan2_riscv_atan2_q15\n");
    printf("RUN atan2_riscv_atan2_q15\n");
    atan2_riscv_atan2_q15();
    printf("PASS benchmark/FastMathFunctions/atan2_riscv_atan2_q15 count=%d\n", 1);
    return 0;
}
