#include <stdio.h>
extern void bayes_riscv_gaussian_naive_bayes_predict_f32(void);

int main(void)
{
    printf("Start benchmark/BayesFunctions/bayes_riscv_gaussian_naive_bayes_predict_f32\n");
    printf("RUN bayes_riscv_gaussian_naive_bayes_predict_f32\n");
    bayes_riscv_gaussian_naive_bayes_predict_f32();
    printf("PASS benchmark/BayesFunctions/bayes_riscv_gaussian_naive_bayes_predict_f32 count=%d\n", 1);
    return 0;
}
