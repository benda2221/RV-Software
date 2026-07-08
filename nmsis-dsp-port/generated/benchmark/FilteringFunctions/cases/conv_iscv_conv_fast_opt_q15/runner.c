#include <stdio.h>
extern void conv_iscv_conv_fast_opt_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/conv_iscv_conv_fast_opt_q15\n");
    printf("RUN conv_iscv_conv_fast_opt_q15\n");
    conv_iscv_conv_fast_opt_q15();
    printf("PASS benchmark/FilteringFunctions/conv_iscv_conv_fast_opt_q15 count=%d\n", 1);
    return 0;
}
