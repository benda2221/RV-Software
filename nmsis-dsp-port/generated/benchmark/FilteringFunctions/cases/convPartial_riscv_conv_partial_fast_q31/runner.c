#include <stdio.h>
extern void convPartial_riscv_conv_partial_fast_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/convPartial_riscv_conv_partial_fast_q31\n");
    printf("RUN convPartial_riscv_conv_partial_fast_q31\n");
    convPartial_riscv_conv_partial_fast_q31();
    printf("PASS benchmark/FilteringFunctions/convPartial_riscv_conv_partial_fast_q31 count=%d\n", 1);
    return 0;
}
