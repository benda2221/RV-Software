#include <stdio.h>
extern void cfft_riscv_cfft_radix2_f32(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/cfft_riscv_cfft_radix2_f32\n");
    printf("RUN cfft_riscv_cfft_radix2_f32\n");
    cfft_riscv_cfft_radix2_f32();
    printf("PASS benchmark/TransformFunctions/cfft_riscv_cfft_radix2_f32 count=%d\n", 1);
    return 0;
}
