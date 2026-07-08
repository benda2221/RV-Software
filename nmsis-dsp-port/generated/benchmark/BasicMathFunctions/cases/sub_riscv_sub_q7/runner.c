#include <stdio.h>
extern void sub_riscv_sub_q7(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/sub_riscv_sub_q7\n");
    printf("RUN sub_riscv_sub_q7\n");
    sub_riscv_sub_q7();
    printf("PASS benchmark/BasicMathFunctions/sub_riscv_sub_q7 count=%d\n", 1);
    return 0;
}
