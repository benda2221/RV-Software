#include <stdio.h>
extern void dct4_riscv_dct4_f32(void);

int main(void)
{
    printf("Start benchmark/TransformFunctions/dct4_riscv_dct4_f32\n");
    printf("RUN dct4_riscv_dct4_f32\n");
    dct4_riscv_dct4_f32();
    printf("PASS benchmark/TransformFunctions/dct4_riscv_dct4_f32 count=%d\n", 1);
    return 0;
}
