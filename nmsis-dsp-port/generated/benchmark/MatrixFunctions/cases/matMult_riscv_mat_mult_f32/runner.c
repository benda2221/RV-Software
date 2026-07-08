#include <stdio.h>
extern void matMult_riscv_mat_mult_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matMult_riscv_mat_mult_f32\n");
    printf("RUN matMult_riscv_mat_mult_f32\n");
    matMult_riscv_mat_mult_f32();
    printf("PASS benchmark/MatrixFunctions/matMult_riscv_mat_mult_f32 count=%d\n", 1);
    return 0;
}
