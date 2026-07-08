#include <stdio.h>
extern void cfft_riscv_cfft_radix2_q15(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/cfft_riscv_cfft_radix2_q15\n");
    printf("RUN cfft_riscv_cfft_radix2_q15\n");
    cfft_riscv_cfft_radix2_q15();
    printf("PASS benchmark/TransformFunctions/cfft_riscv_cfft_radix2_q15 count=%d\n", 1);
    return 0;
}
