#include <stdio.h>
extern void logsumexpDotProd_riscv_logsumexp_dot_prod_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/logsumexpDotProd_riscv_logsumexp_dot_prod_f32\n");
    printf("RUN logsumexpDotProd_riscv_logsumexp_dot_prod_f32\n");
    logsumexpDotProd_riscv_logsumexp_dot_prod_f32();
    printf("PASS benchmark/StatisticsFunctions/logsumexpDotProd_riscv_logsumexp_dot_prod_f32 count=%d\n", 1);
    return 0;
}
