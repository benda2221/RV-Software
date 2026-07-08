#include <stdio.h>
extern void rfft_riscv_rfft_fast_f32(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/rfft_riscv_rfft_fast_f32\n");
    printf("RUN rfft_riscv_rfft_fast_f32\n");
    rfft_riscv_rfft_fast_f32();
    printf("PASS benchmark/TransformFunctions/rfft_riscv_rfft_fast_f32 count=%d\n", 1);
    return 0;
}
