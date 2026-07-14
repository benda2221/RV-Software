#include <stdio.h>
extern void f32ToQ7_riscv_float_to_q7(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/f32ToQ7_riscv_float_to_q7\n");
    printf("RUN f32ToQ7_riscv_float_to_q7\n");
    f32ToQ7_riscv_float_to_q7();
    printf("PASS benchmark/SupportFunctions/f32ToQ7_riscv_float_to_q7 count=%d\n", 1);
    return 0;
}
