#include <stdio.h>
extern void atan2_riscv_atan2_q31(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/atan2_riscv_atan2_q31\n");
    printf("RUN atan2_riscv_atan2_q31\n");
    atan2_riscv_atan2_q31();
    printf("PASS benchmark/FastMathFunctions/atan2_riscv_atan2_q31 count=%d\n", 1);
    return 0;
}
