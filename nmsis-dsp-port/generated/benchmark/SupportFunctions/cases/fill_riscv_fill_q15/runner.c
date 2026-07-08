#include <stdio.h>
extern void fill_riscv_fill_q15(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/fill_riscv_fill_q15\n");
    printf("RUN fill_riscv_fill_q15\n");
    fill_riscv_fill_q15();
    printf("PASS benchmark/SupportFunctions/fill_riscv_fill_q15 count=%d\n", 1);
    return 0;
}
