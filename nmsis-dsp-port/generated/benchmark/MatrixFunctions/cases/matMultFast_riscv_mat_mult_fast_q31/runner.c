#include <stdio.h>
extern void matMultFast_riscv_mat_mult_fast_q31(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matMultFast_riscv_mat_mult_fast_q31\n");
    printf("RUN matMultFast_riscv_mat_mult_fast_q31\n");
    matMultFast_riscv_mat_mult_fast_q31();
    printf("PASS benchmark/MatrixFunctions/matMultFast_riscv_mat_mult_fast_q31 count=%d\n", 1);
    return 0;
}
