#include <stdio.h>
extern void copy_riscv_copy_q7(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/copy_riscv_copy_q7\n");
    printf("RUN copy_riscv_copy_q7\n");
    copy_riscv_copy_q7();
    printf("PASS benchmark/SupportFunctions/copy_riscv_copy_q7 count=%d\n", 1);
    return 0;
}
