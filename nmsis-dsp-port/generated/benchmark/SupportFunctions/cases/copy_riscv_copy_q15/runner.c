#include <stdio.h>
extern void copy_riscv_copy_q15(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/copy_riscv_copy_q15\n");
    printf("RUN copy_riscv_copy_q15\n");
    copy_riscv_copy_q15();
    printf("PASS benchmark/SupportFunctions/copy_riscv_copy_q15 count=%d\n", 1);
    return 0;
}
