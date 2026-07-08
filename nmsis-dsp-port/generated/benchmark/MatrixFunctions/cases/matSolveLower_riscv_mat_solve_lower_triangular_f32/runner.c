#include <stdio.h>
extern void matSolveLower_riscv_mat_solve_lower_triangular_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matSolveLower_riscv_mat_solve_lower_triangular_f32\n");
    printf("RUN matSolveLower_riscv_mat_solve_lower_triangular_f32\n");
    matSolveLower_riscv_mat_solve_lower_triangular_f32();
    printf("PASS benchmark/MatrixFunctions/matSolveLower_riscv_mat_solve_lower_triangular_f32 count=%d\n", 1);
    return 0;
}
