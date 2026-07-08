#include <stdio.h>
extern void levinsonDurbin_riscv_levinson_durbin_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/levinsonDurbin_riscv_levinson_durbin_q31\n");
    printf("RUN levinsonDurbin_riscv_levinson_durbin_q31\n");
    levinsonDurbin_riscv_levinson_durbin_q31();
    printf("PASS benchmark/FilteringFunctions/levinsonDurbin_riscv_levinson_durbin_q31 count=%d\n", 1);
    return 0;
}
