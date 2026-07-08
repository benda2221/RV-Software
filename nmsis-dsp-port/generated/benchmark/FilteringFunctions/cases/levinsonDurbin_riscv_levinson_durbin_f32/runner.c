#include <stdio.h>
extern void levinsonDurbin_riscv_levinson_durbin_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/levinsonDurbin_riscv_levinson_durbin_f32\n");
    printf("RUN levinsonDurbin_riscv_levinson_durbin_f32\n");
    levinsonDurbin_riscv_levinson_durbin_f32();
    printf("PASS benchmark/FilteringFunctions/levinsonDurbin_riscv_levinson_durbin_f32 count=%d\n", 1);
    return 0;
}
