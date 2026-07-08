#include <stdio.h>
extern void matScale_riscv_mat_scale_q15(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matScale_riscv_mat_scale_q15\n");
    printf("RUN matScale_riscv_mat_scale_q15\n");
    matScale_riscv_mat_scale_q15();
    printf("PASS benchmark/MatrixFunctions/matScale_riscv_mat_scale_q15 count=%d\n", 1);
    return 0;
}
