#include <stdio.h>
extern void matScale_riscv_mat_scale_q31(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matScale_riscv_mat_scale_q31\n");
    printf("RUN matScale_riscv_mat_scale_q31\n");
    matScale_riscv_mat_scale_q31();
    printf("PASS benchmark/MatrixFunctions/matScale_riscv_mat_scale_q31 count=%d\n", 1);
    return 0;
}
