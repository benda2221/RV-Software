#include <stdio.h>
extern void conv_riscv_conv_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/conv_riscv_conv_f32\n");
    printf("RUN conv_riscv_conv_f32\n");
    conv_riscv_conv_f32();
    printf("PASS benchmark/FilteringFunctions/conv_riscv_conv_f32 count=%d\n", 1);
    return 0;
}
