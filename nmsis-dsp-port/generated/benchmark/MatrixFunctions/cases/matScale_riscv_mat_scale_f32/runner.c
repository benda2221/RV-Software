#include <stdio.h>
extern void matScale_riscv_mat_scale_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matScale_riscv_mat_scale_f32\n");
    printf("RUN matScale_riscv_mat_scale_f32\n");
    matScale_riscv_mat_scale_f32();
    printf("PASS benchmark/MatrixFunctions/matScale_riscv_mat_scale_f32 count=%d\n", 1);
    return 0;
}
