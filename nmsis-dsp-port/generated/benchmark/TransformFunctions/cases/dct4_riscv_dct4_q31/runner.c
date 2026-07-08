#include <stdio.h>
extern void dct4_riscv_dct4_q31(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/dct4_riscv_dct4_q31\n");
    printf("RUN dct4_riscv_dct4_q31\n");
    dct4_riscv_dct4_q31();
    printf("PASS benchmark/TransformFunctions/dct4_riscv_dct4_q31 count=%d\n", 1);
    return 0;
}
