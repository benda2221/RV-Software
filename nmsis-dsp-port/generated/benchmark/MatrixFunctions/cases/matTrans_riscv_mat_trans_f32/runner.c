#include <stdio.h>
extern void matTrans_riscv_mat_trans_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matTrans_riscv_mat_trans_f32\n");
    printf("RUN matTrans_riscv_mat_trans_f32\n");
    matTrans_riscv_mat_trans_f32();
    printf("PASS benchmark/MatrixFunctions/matTrans_riscv_mat_trans_f32 count=%d\n", 1);
    return 0;
}
