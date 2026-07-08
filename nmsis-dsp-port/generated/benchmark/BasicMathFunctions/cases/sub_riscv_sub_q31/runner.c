#include <stdio.h>
extern void sub_riscv_sub_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/sub_riscv_sub_q31\n");
    printf("RUN sub_riscv_sub_q31\n");
    sub_riscv_sub_q31();
    printf("PASS benchmark/BasicMathFunctions/sub_riscv_sub_q31 count=%d\n", 1);
    return 0;
}
