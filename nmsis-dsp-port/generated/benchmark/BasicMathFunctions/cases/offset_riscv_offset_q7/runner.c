#include <stdio.h>
extern void offset_riscv_offset_q7(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/offset_riscv_offset_q7\n");
    printf("RUN offset_riscv_offset_q7\n");
    offset_riscv_offset_q7();
    printf("PASS benchmark/BasicMathFunctions/offset_riscv_offset_q7 count=%d\n", 1);
    return 0;
}
