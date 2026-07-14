#include <stdio.h>
extern void rms_riscv_rms_f32(void);

int main(void)
{
    printf("Start benchmark/StatisticsFunctions/rms_riscv_rms_f32\n");
    printf("RUN rms_riscv_rms_f32\n");
    rms_riscv_rms_f32();
    printf("PASS benchmark/StatisticsFunctions/rms_riscv_rms_f32 count=%d\n", 1);
    return 0;
}
