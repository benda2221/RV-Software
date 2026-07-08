#include <stdio.h>
extern void firSparse_riscv_fir_sparse_q31(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firSparse_riscv_fir_sparse_q31\n");
    printf("RUN firSparse_riscv_fir_sparse_q31\n");
    firSparse_riscv_fir_sparse_q31();
    printf("PASS benchmark/FilteringFunctions/firSparse_riscv_fir_sparse_q31 count=%d\n", 1);
    return 0;
}
