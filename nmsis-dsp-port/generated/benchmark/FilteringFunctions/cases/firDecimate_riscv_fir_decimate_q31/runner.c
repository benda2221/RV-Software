#include <stdio.h>
extern void firDecimate_riscv_fir_decimate_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firDecimate_riscv_fir_decimate_q31\n");
    printf("RUN firDecimate_riscv_fir_decimate_q31\n");
    firDecimate_riscv_fir_decimate_q31();
    printf("PASS benchmark/FilteringFunctions/firDecimate_riscv_fir_decimate_q31 count=%d\n", 1);
    return 0;
}
