#include <stdio.h>
extern void matInverse_riscv_mat_inverse_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matInverse_riscv_mat_inverse_f32\n");
    printf("RUN matInverse_riscv_mat_inverse_f32\n");
    matInverse_riscv_mat_inverse_f32();
    printf("PASS benchmark/MatrixFunctions/matInverse_riscv_mat_inverse_f32 count=%d\n", 1);
    return 0;
}
