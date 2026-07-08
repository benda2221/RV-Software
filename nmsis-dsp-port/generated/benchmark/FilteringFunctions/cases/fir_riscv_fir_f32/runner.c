#include <stdio.h>
extern void fir_riscv_fir_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/fir_riscv_fir_f32\n");
    printf("RUN fir_riscv_fir_f32\n");
    fir_riscv_fir_f32();
    printf("PASS benchmark/FilteringFunctions/fir_riscv_fir_f32 count=%d\n", 1);
    return 0;
}
