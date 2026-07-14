#include <stdio.h>
extern void vexp_riscv_vexp_f32(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions/vexp_riscv_vexp_f32\n");
    printf("RUN vexp_riscv_vexp_f32\n");
    vexp_riscv_vexp_f32();
    printf("PASS benchmark/FastMathFunctions/vexp_riscv_vexp_f32 count=%d\n", 1);
    return 0;
}
