#include <stdio.h>
extern void linear_riscv_linear_interp_q31(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions/linear_riscv_linear_interp_q31\n");
    printf("RUN linear_riscv_linear_interp_q31\n");
    linear_riscv_linear_interp_q31();
    printf("PASS benchmark/InterpolationFunctions/linear_riscv_linear_interp_q31 count=%d\n", 1);
    return 0;
}
