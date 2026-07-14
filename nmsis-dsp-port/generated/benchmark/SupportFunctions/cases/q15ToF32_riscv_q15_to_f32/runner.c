#include <stdio.h>
extern void q15ToF32_riscv_q15_to_f32(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q15ToF32_riscv_q15_to_f32\n");
    printf("RUN q15ToF32_riscv_q15_to_f32\n");
    q15ToF32_riscv_q15_to_f32();
    printf("PASS benchmark/SupportFunctions/q15ToF32_riscv_q15_to_f32 count=%d\n", 1);
    return 0;
}
