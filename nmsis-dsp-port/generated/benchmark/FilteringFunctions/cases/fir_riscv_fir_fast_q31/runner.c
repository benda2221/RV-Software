#include <stdio.h>
extern void fir_riscv_fir_fast_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/fir_riscv_fir_fast_q31\n");
    printf("RUN fir_riscv_fir_fast_q31\n");
    fir_riscv_fir_fast_q31();
    printf("PASS benchmark/FilteringFunctions/fir_riscv_fir_fast_q31 count=%d\n", 1);
    return 0;
}
