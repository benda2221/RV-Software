#include <stdio.h>
extern void matAdd_riscv_mat_add_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matAdd_riscv_mat_add_f32\n");
    printf("RUN matAdd_riscv_mat_add_f32\n");
    matAdd_riscv_mat_add_f32();
    printf("PASS benchmark/MatrixFunctions/matAdd_riscv_mat_add_f32 count=%d\n", 1);
    return 0;
}
