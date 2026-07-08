#include <stdio.h>
extern void conv_riscv_conv_opt_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/conv_riscv_conv_opt_q15\n");
    printf("RUN conv_riscv_conv_opt_q15\n");
    conv_riscv_conv_opt_q15();
    printf("PASS benchmark/FilteringFunctions/conv_riscv_conv_opt_q15 count=%d\n", 1);
    return 0;
}
