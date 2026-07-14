#include <stdio.h>
extern void matCholesky_riscv_mat_cholesky_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matCholesky_riscv_mat_cholesky_f32\n");
    printf("RUN matCholesky_riscv_mat_cholesky_f32\n");
    matCholesky_riscv_mat_cholesky_f32();
    printf("PASS benchmark/MatrixFunctions/matCholesky_riscv_mat_cholesky_f32 count=%d\n", 1);
    return 0;
}
