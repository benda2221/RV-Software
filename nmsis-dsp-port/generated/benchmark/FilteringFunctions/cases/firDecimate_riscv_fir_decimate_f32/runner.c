#include <stdio.h>
extern void firDecimate_riscv_fir_decimate_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firDecimate_riscv_fir_decimate_f32\n");
    printf("RUN firDecimate_riscv_fir_decimate_f32\n");
    firDecimate_riscv_fir_decimate_f32();
    printf("PASS benchmark/FilteringFunctions/firDecimate_riscv_fir_decimate_f32 count=%d\n", 1);
    return 0;
}
