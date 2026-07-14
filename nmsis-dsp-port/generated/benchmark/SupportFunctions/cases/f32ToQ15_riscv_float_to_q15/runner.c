#include <stdio.h>
extern void f32ToQ15_riscv_float_to_q15(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/f32ToQ15_riscv_float_to_q15\n");
    printf("RUN f32ToQ15_riscv_float_to_q15\n");
    f32ToQ15_riscv_float_to_q15();
    printf("PASS benchmark/SupportFunctions/f32ToQ15_riscv_float_to_q15 count=%d\n", 1);
    return 0;
}
