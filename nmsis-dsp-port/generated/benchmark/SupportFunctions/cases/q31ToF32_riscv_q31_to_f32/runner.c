#include <stdio.h>
extern void q31ToF32_riscv_q31_to_f32(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q31ToF32_riscv_q31_to_f32\n");
    printf("RUN q31ToF32_riscv_q31_to_f32\n");
    q31ToF32_riscv_q31_to_f32();
    printf("PASS benchmark/SupportFunctions/q31ToF32_riscv_q31_to_f32 count=%d\n", 1);
    return 0;
}
