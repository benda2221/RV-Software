#include <stdio.h>
extern void rms_riscv_rms_q15(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/rms_riscv_rms_q15\n");
    printf("RUN rms_riscv_rms_q15\n");
    rms_riscv_rms_q15();
    printf("PASS benchmark/StatisticsFunctions/rms_riscv_rms_q15 count=%d\n", 1);
    return 0;
}
