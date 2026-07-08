#include <stdio.h>
extern void convPartial_riscv_conv_partial_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/convPartial_riscv_conv_partial_f32\n");
    printf("RUN convPartial_riscv_conv_partial_f32\n");
    convPartial_riscv_conv_partial_f32();
    printf("PASS benchmark/FilteringFunctions/convPartial_riscv_conv_partial_f32 count=%d\n", 1);
    return 0;
}
