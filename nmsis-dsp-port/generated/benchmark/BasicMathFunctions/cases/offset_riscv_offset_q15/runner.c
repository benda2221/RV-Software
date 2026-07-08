#include <stdio.h>
extern void offset_riscv_offset_q15(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/offset_riscv_offset_q15\n");
    printf("RUN offset_riscv_offset_q15\n");
    offset_riscv_offset_q15();
    printf("PASS benchmark/BasicMathFunctions/offset_riscv_offset_q15 count=%d\n", 1);
    return 0;
}
