#include <stdio.h>
extern void convPartial_riscv_conv_partial_opt_q7(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/convPartial_riscv_conv_partial_opt_q7\n");
    printf("RUN convPartial_riscv_conv_partial_opt_q7\n");
    convPartial_riscv_conv_partial_opt_q7();
    printf("PASS benchmark/FilteringFunctions/convPartial_riscv_conv_partial_opt_q7 count=%d\n", 1);
    return 0;
}
