#include <stdio.h>
extern void svm_riscv_svm_linear_predict_f32(void);
extern void svm_riscv_svm_polynomial_predict_f32(void);

int main(void)
{
    printf("Start benchmark/SVMFunctions\n");
    printf("RUN svm_riscv_svm_linear_predict_f32\n");
    svm_riscv_svm_linear_predict_f32();
    printf("RUN svm_riscv_svm_polynomial_predict_f32\n");
    svm_riscv_svm_polynomial_predict_f32();
    printf("PASS benchmark/SVMFunctions count=%d\n", 2);
    return 0;
}
