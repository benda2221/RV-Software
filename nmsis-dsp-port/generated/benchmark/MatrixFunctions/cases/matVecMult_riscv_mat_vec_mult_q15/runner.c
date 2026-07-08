#include <stdio.h>
extern void matVecMult_riscv_mat_vec_mult_q15(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matVecMult_riscv_mat_vec_mult_q15\n");
    printf("RUN matVecMult_riscv_mat_vec_mult_q15\n");
    matVecMult_riscv_mat_vec_mult_q15();
    printf("PASS benchmark/MatrixFunctions/matVecMult_riscv_mat_vec_mult_q15 count=%d\n", 1);
    return 0;
}
