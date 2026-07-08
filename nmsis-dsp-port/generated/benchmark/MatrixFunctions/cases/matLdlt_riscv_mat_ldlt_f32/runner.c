#include <stdio.h>
extern void matLdlt_riscv_mat_ldlt_f32(void);

int main(void)
{
    printf("Start benchmark/MatrixFunctions/matLdlt_riscv_mat_ldlt_f32\n");
    printf("RUN matLdlt_riscv_mat_ldlt_f32\n");
    matLdlt_riscv_mat_ldlt_f32();
    printf("PASS benchmark/MatrixFunctions/matLdlt_riscv_mat_ldlt_f32 count=%d\n", 1);
    return 0;
}
