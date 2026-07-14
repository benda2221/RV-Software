#include <stdio.h>
extern void f32ToQ31_riscv_float_to_q31(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/f32ToQ31_riscv_float_to_q31\n");
    printf("RUN f32ToQ31_riscv_float_to_q31\n");
    f32ToQ31_riscv_float_to_q31();
    printf("PASS benchmark/SupportFunctions/f32ToQ31_riscv_float_to_q31 count=%d\n", 1);
    return 0;
}
