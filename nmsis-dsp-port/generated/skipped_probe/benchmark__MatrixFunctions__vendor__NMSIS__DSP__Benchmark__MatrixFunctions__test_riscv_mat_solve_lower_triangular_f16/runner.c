#include <stdio.h>
extern void matSolveLower_riscv_mat_solve_lower_triangular_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__MatrixFunctions__vendor__NMSIS__DSP__Benchmark__MatrixFunctions__test_riscv_mat_solve_lower_triangular_f16\n");
    printf("RUN matSolveLower_riscv_mat_solve_lower_triangular_f16\n");
    matSolveLower_riscv_mat_solve_lower_triangular_f16();
    printf("PASS skipped-probe/benchmark__MatrixFunctions__vendor__NMSIS__DSP__Benchmark__MatrixFunctions__test_riscv_mat_solve_lower_triangular_f16 count=%d\n", 1);
    return 0;
}
