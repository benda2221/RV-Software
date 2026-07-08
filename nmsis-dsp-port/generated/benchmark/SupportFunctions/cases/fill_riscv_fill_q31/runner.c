#include <stdio.h>
extern void fill_riscv_fill_q31(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/fill_riscv_fill_q31\n");
    printf("RUN fill_riscv_fill_q31\n");
    fill_riscv_fill_q31();
    printf("PASS benchmark/SupportFunctions/fill_riscv_fill_q31 count=%d\n", 1);
    return 0;
}
