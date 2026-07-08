#include <stdio.h>
extern void shift_riscv_shift_q7(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/shift_riscv_shift_q7\n");
    printf("RUN shift_riscv_shift_q7\n");
    shift_riscv_shift_q7();
    printf("PASS benchmark/BasicMathFunctions/shift_riscv_shift_q7 count=%d\n", 1);
    return 0;
}
