#include <stdio.h>
extern void rfft_riscv_rfft_q15(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/rfft_riscv_rfft_q15\n");
    printf("RUN rfft_riscv_rfft_q15\n");
    rfft_riscv_rfft_q15();
    printf("PASS benchmark/TransformFunctions/rfft_riscv_rfft_q15 count=%d\n", 1);
    return 0;
}
