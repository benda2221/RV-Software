#include <stdio.h>
extern void matSolveUpper_riscv_mat_solve_upper_triangular_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matSolveUpper_riscv_mat_solve_upper_triangular_f32\n");
    printf("RUN matSolveUpper_riscv_mat_solve_upper_triangular_f32\n");
    matSolveUpper_riscv_mat_solve_upper_triangular_f32();
    printf("PASS benchmark/MatrixFunctions/matSolveUpper_riscv_mat_solve_upper_triangular_f32 count=%d\n", 1);
    return 0;
}
