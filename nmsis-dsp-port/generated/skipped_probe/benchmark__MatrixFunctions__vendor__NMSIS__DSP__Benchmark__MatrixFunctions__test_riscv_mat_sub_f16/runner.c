#include <stdio.h>
extern void matSub_riscv_mat_sub_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__MatrixFunctions__vendor__NMSIS__DSP__Benchmark__MatrixFunctions__test_riscv_mat_sub_f16\n");
    printf("RUN matSub_riscv_mat_sub_f16\n");
    matSub_riscv_mat_sub_f16();
    printf("PASS skipped-probe/benchmark__MatrixFunctions__vendor__NMSIS__DSP__Benchmark__MatrixFunctions__test_riscv_mat_sub_f16 count=%d\n", 1);
    return 0;
}
