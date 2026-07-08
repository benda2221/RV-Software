#include <stdio.h>
extern void linear_riscv_linear_interp_q7(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions/linear_riscv_linear_interp_q7\n");
    printf("RUN linear_riscv_linear_interp_q7\n");
    linear_riscv_linear_interp_q7();
    printf("PASS benchmark/InterpolationFunctions/linear_riscv_linear_interp_q7 count=%d\n", 1);
    return 0;
}
