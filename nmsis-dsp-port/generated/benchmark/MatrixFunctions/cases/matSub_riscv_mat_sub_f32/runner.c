#include <stdio.h>
extern void matSub_riscv_mat_sub_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matSub_riscv_mat_sub_f32\n");
    printf("RUN matSub_riscv_mat_sub_f32\n");
    matSub_riscv_mat_sub_f32();
    printf("PASS benchmark/MatrixFunctions/matSub_riscv_mat_sub_f32 count=%d\n", 1);
    return 0;
}
