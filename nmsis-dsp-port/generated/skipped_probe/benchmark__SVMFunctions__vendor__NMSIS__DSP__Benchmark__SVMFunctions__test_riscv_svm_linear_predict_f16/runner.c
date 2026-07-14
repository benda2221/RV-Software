#include <stdio.h>
extern void svm_riscv_svm_linear_predict_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__SVMFunctions__vendor__NMSIS__DSP__Benchmark__SVMFunctions__test_riscv_svm_linear_predict_f16\n");
    printf("RUN svm_riscv_svm_linear_predict_f16\n");
    svm_riscv_svm_linear_predict_f16();
    printf("PASS skipped-probe/benchmark__SVMFunctions__vendor__NMSIS__DSP__Benchmark__SVMFunctions__test_riscv_svm_linear_predict_f16 count=%d\n", 1);
    return 0;
}
