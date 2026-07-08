#include <stdio.h>
extern void firSparse_riscv_fir_sparse_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/firSparse_riscv_fir_sparse_f32\n");
    printf("RUN firSparse_riscv_fir_sparse_f32\n");
    firSparse_riscv_fir_sparse_f32();
    printf("PASS benchmark/FilteringFunctions/firSparse_riscv_fir_sparse_f32 count=%d\n", 1);
    return 0;
}
