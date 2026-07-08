#include <stdio.h>
extern void matMultOpt_riscv_mat_mult_opt_q31(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matMultOpt_riscv_mat_mult_opt_q31\n");
    printf("RUN matMultOpt_riscv_mat_mult_opt_q31\n");
    matMultOpt_riscv_mat_mult_opt_q31();
    printf("PASS benchmark/MatrixFunctions/matMultOpt_riscv_mat_mult_opt_q31 count=%d\n", 1);
    return 0;
}
