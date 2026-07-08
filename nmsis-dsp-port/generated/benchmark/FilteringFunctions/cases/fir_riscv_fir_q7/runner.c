#include <stdio.h>
extern void fir_riscv_fir_q7(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/fir_riscv_fir_q7\n");
    printf("RUN fir_riscv_fir_q7\n");
    fir_riscv_fir_q7();
    printf("PASS benchmark/FilteringFunctions/fir_riscv_fir_q7 count=%d\n", 1);
    return 0;
}
