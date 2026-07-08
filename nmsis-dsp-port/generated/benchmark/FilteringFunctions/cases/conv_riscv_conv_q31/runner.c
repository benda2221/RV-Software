#include <stdio.h>
extern void conv_riscv_conv_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/conv_riscv_conv_q31\n");
    printf("RUN conv_riscv_conv_q31\n");
    conv_riscv_conv_q31();
    printf("PASS benchmark/FilteringFunctions/conv_riscv_conv_q31 count=%d\n", 1);
    return 0;
}
