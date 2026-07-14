#include <stdio.h>
extern void svm_riscv_svm_rbf_predict_f32(void);

int main(void)
{
    printf("Start benchmark/SVMFunctions/svm_riscv_svm_rbf_predict_f32\n");
    printf("RUN svm_riscv_svm_rbf_predict_f32\n");
    svm_riscv_svm_rbf_predict_f32();
    printf("PASS benchmark/SVMFunctions/svm_riscv_svm_rbf_predict_f32 count=%d\n", 1);
    return 0;
}
