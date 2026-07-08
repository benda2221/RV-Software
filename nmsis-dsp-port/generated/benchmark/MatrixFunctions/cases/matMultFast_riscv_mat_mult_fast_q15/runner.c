#include <stdio.h>
extern void matMultFast_riscv_mat_mult_fast_q15(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matMultFast_riscv_mat_mult_fast_q15\n");
    printf("RUN matMultFast_riscv_mat_mult_fast_q15\n");
    matMultFast_riscv_mat_mult_fast_q15();
    printf("PASS benchmark/MatrixFunctions/matMultFast_riscv_mat_mult_fast_q15 count=%d\n", 1);
    return 0;
}
