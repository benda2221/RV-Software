#include <stdio.h>
extern void shift_riscv_shift_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/shift_riscv_shift_q15\n");
    printf("RUN shift_riscv_shift_q15\n");
    shift_riscv_shift_q15();
    printf("PASS benchmark/BasicMathFunctions/shift_riscv_shift_q15 count=%d\n", 1);
    return 0;
}
