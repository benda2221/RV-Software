#include <stdio.h>
extern void matTrans_riscv_mat_trans_q15(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matTrans_riscv_mat_trans_q15\n");
    printf("RUN matTrans_riscv_mat_trans_q15\n");
    matTrans_riscv_mat_trans_q15();
    printf("PASS benchmark/MatrixFunctions/matTrans_riscv_mat_trans_q15 count=%d\n", 1);
    return 0;
}
