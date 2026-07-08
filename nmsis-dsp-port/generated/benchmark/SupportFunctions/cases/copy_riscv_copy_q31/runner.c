#include <stdio.h>
extern void copy_riscv_copy_q31(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/copy_riscv_copy_q31\n");
    printf("RUN copy_riscv_copy_q31\n");
    copy_riscv_copy_q31();
    printf("PASS benchmark/SupportFunctions/copy_riscv_copy_q31 count=%d\n", 1);
    return 0;
}
