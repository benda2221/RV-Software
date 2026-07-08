#include <stdio.h>
extern void rms_riscv_rms_q31(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/rms_riscv_rms_q31\n");
    printf("RUN rms_riscv_rms_q31\n");
    rms_riscv_rms_q31();
    printf("PASS benchmark/StatisticsFunctions/rms_riscv_rms_q31 count=%d\n", 1);
    return 0;
}
