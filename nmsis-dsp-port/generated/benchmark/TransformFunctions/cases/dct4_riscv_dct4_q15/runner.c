#include <stdio.h>
extern void dct4_riscv_dct4_q15(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/dct4_riscv_dct4_q15\n");
    printf("RUN dct4_riscv_dct4_q15\n");
    dct4_riscv_dct4_q15();
    printf("PASS benchmark/TransformFunctions/dct4_riscv_dct4_q15 count=%d\n", 1);
    return 0;
}
