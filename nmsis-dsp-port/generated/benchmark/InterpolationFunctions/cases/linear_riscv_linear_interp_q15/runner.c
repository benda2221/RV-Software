#include <stdio.h>
extern void linear_riscv_linear_interp_q15(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions/linear_riscv_linear_interp_q15\n");
    printf("RUN linear_riscv_linear_interp_q15\n");
    linear_riscv_linear_interp_q15();
    printf("PASS benchmark/InterpolationFunctions/linear_riscv_linear_interp_q15 count=%d\n", 1);
    return 0;
}
