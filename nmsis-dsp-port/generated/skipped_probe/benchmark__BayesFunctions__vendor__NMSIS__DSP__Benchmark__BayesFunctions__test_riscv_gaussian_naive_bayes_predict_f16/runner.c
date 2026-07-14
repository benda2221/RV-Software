#include <stdio.h>
extern void bayes_riscv_gaussian_naive_bayes_predict_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__BayesFunctions__vendor__NMSIS__DSP__Benchmark__BayesFunctions__test_riscv_gaussian_naive_bayes_predict_f16\n");
    printf("RUN bayes_riscv_gaussian_naive_bayes_predict_f16\n");
    bayes_riscv_gaussian_naive_bayes_predict_f16();
    printf("PASS skipped-probe/benchmark__BayesFunctions__vendor__NMSIS__DSP__Benchmark__BayesFunctions__test_riscv_gaussian_naive_bayes_predict_f16 count=%d\n", 1);
    return 0;
}
