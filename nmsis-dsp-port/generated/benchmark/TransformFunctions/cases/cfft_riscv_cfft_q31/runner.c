#include <stdio.h>
extern void cfft_riscv_cfft_q31(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/cfft_riscv_cfft_q31\n");
    printf("RUN cfft_riscv_cfft_q31\n");
    cfft_riscv_cfft_q31();
    printf("PASS benchmark/TransformFunctions/cfft_riscv_cfft_q31 count=%d\n", 1);
    return 0;
}
