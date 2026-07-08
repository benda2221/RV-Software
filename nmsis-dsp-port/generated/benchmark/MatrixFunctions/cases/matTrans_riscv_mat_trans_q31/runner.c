#include <stdio.h>
extern void matTrans_riscv_mat_trans_q31(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matTrans_riscv_mat_trans_q31\n");
    printf("RUN matTrans_riscv_mat_trans_q31\n");
    matTrans_riscv_mat_trans_q31();
    printf("PASS benchmark/MatrixFunctions/matTrans_riscv_mat_trans_q31 count=%d\n", 1);
    return 0;
}
