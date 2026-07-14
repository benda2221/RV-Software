#include <stdio.h>
extern void q7ToF32_riscv_q7_to_float(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/q7ToF32_riscv_q7_to_float\n");
    printf("RUN q7ToF32_riscv_q7_to_float\n");
    q7ToF32_riscv_q7_to_float();
    printf("PASS benchmark/SupportFunctions/q7ToF32_riscv_q7_to_float count=%d\n", 1);
    return 0;
}
