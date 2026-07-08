#include <stdio.h>
extern void matAdd_riscv_mat_add_q15(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matAdd_riscv_mat_add_q15\n");
    printf("RUN matAdd_riscv_mat_add_q15\n");
    matAdd_riscv_mat_add_q15();
    printf("PASS benchmark/MatrixFunctions/matAdd_riscv_mat_add_q15 count=%d\n", 1);
    return 0;
}
