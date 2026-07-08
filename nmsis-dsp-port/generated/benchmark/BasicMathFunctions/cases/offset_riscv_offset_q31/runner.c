#include <stdio.h>
extern void offset_riscv_offset_q31(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/offset_riscv_offset_q31\n");
    printf("RUN offset_riscv_offset_q31\n");
    offset_riscv_offset_q31();
    printf("PASS benchmark/BasicMathFunctions/offset_riscv_offset_q31 count=%d\n", 1);
    return 0;
}
