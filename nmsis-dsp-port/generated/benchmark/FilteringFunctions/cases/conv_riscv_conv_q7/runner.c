#include <stdio.h>
extern void conv_riscv_conv_q7(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/conv_riscv_conv_q7\n");
    printf("RUN conv_riscv_conv_q7\n");
    conv_riscv_conv_q7();
    printf("PASS benchmark/FilteringFunctions/conv_riscv_conv_q7 count=%d\n", 1);
    return 0;
}
