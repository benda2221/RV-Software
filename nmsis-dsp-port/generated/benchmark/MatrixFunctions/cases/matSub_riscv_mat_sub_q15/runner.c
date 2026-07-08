#include <stdio.h>
extern void matSub_riscv_mat_sub_q15(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matSub_riscv_mat_sub_q15\n");
    printf("RUN matSub_riscv_mat_sub_q15\n");
    matSub_riscv_mat_sub_q15();
    printf("PASS benchmark/MatrixFunctions/matSub_riscv_mat_sub_q15 count=%d\n", 1);
    return 0;
}
