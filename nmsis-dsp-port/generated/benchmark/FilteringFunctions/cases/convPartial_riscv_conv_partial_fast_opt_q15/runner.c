#include <stdio.h>
extern void convPartial_riscv_conv_partial_fast_opt_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/convPartial_riscv_conv_partial_fast_opt_q15\n");
    printf("RUN convPartial_riscv_conv_partial_fast_opt_q15\n");
    convPartial_riscv_conv_partial_fast_opt_q15();
    printf("PASS benchmark/FilteringFunctions/convPartial_riscv_conv_partial_fast_opt_q15 count=%d\n", 1);
    return 0;
}
