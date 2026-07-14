#include <stdio.h>
extern void fir_riscv_fir_fast_q15(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/fir_riscv_fir_fast_q15\n");
    printf("RUN fir_riscv_fir_fast_q15\n");
    fir_riscv_fir_fast_q15();
    printf("PASS benchmark/FilteringFunctions/fir_riscv_fir_fast_q15 count=%d\n", 1);
    return 0;
}
