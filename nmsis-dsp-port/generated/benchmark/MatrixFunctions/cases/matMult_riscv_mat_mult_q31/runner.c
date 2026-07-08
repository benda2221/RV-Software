#include <stdio.h>
extern void matMult_riscv_mat_mult_q31(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matMult_riscv_mat_mult_q31\n");
    printf("RUN matMult_riscv_mat_mult_q31\n");
    matMult_riscv_mat_mult_q31();
    printf("PASS benchmark/MatrixFunctions/matMult_riscv_mat_mult_q31 count=%d\n", 1);
    return 0;
}
