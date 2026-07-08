#include <stdio.h>
extern void sub_riscv_sub_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/sub_riscv_sub_q15\n");
    printf("RUN sub_riscv_sub_q15\n");
    sub_riscv_sub_q15();
    printf("PASS benchmark/BasicMathFunctions/sub_riscv_sub_q15 count=%d\n", 1);
    return 0;
}
