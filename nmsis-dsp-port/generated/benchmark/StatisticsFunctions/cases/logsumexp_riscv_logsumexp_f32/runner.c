#include <stdio.h>
extern void logsumexp_riscv_logsumexp_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/logsumexp_riscv_logsumexp_f32\n");
    printf("RUN logsumexp_riscv_logsumexp_f32\n");
    logsumexp_riscv_logsumexp_f32();
    printf("PASS benchmark/StatisticsFunctions/logsumexp_riscv_logsumexp_f32 count=%d\n", 1);
    return 0;
}
