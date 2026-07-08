#include <stdio.h>
extern void fill_riscv_fill_q7(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/fill_riscv_fill_q7\n");
    printf("RUN fill_riscv_fill_q7\n");
    fill_riscv_fill_q7();
    printf("PASS benchmark/SupportFunctions/fill_riscv_fill_q7 count=%d\n", 1);
    return 0;
}
