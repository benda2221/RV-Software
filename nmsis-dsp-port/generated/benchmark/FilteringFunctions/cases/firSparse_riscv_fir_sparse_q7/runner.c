#include <stdio.h>
extern void firSparse_riscv_fir_sparse_q7(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firSparse_riscv_fir_sparse_q7\n");
    printf("RUN firSparse_riscv_fir_sparse_q7\n");
    firSparse_riscv_fir_sparse_q7();
    printf("PASS benchmark/FilteringFunctions/firSparse_riscv_fir_sparse_q7 count=%d\n", 1);
    return 0;
}
