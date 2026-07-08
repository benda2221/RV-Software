#include <stdio.h>
extern void shift_riscv_shift_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/shift_riscv_shift_q31\n");
    printf("RUN shift_riscv_shift_q31\n");
    shift_riscv_shift_q31();
    printf("PASS benchmark/BasicMathFunctions/shift_riscv_shift_q31 count=%d\n", 1);
    return 0;
}
