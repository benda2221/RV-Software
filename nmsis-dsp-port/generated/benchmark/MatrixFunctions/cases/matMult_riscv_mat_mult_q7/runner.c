#include <stdio.h>
extern void matMult_riscv_mat_mult_q7(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matMult_riscv_mat_mult_q7\n");
    printf("RUN matMult_riscv_mat_mult_q7\n");
    matMult_riscv_mat_mult_q7();
    printf("PASS benchmark/MatrixFunctions/matMult_riscv_mat_mult_q7 count=%d\n", 1);
    return 0;
}
