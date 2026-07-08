#include <stdio.h>
extern void matAdd_riscv_mat_add_q31(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matAdd_riscv_mat_add_q31\n");
    printf("RUN matAdd_riscv_mat_add_q31\n");
    matAdd_riscv_mat_add_q31();
    printf("PASS benchmark/MatrixFunctions/matAdd_riscv_mat_add_q31 count=%d\n", 1);
    return 0;
}
