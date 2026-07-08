#include <stdio.h>
extern void firDecimate_riscv_fir_decimate_fast_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firDecimate_riscv_fir_decimate_fast_q15\n");
    printf("RUN firDecimate_riscv_fir_decimate_fast_q15\n");
    firDecimate_riscv_fir_decimate_fast_q15();
    printf("PASS benchmark/FilteringFunctions/firDecimate_riscv_fir_decimate_fast_q15 count=%d\n", 1);
    return 0;
}
