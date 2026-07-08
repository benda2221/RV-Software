#include <stdio.h>
extern void rfft_riscv_rfft_q31(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/rfft_riscv_rfft_q31\n");
    printf("RUN rfft_riscv_rfft_q31\n");
    rfft_riscv_rfft_q31();
    printf("PASS benchmark/TransformFunctions/rfft_riscv_rfft_q31 count=%d\n", 1);
    return 0;
}
