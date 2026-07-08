#include <stdio.h>
extern void matSub_riscv_mat_sub_q31(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matSub_riscv_mat_sub_q31\n");
    printf("RUN matSub_riscv_mat_sub_q31\n");
    matSub_riscv_mat_sub_q31();
    printf("PASS benchmark/MatrixFunctions/matSub_riscv_mat_sub_q31 count=%d\n", 1);
    return 0;
}
