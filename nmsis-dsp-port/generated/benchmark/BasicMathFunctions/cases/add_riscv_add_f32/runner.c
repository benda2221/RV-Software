#include <stdio.h>
extern void add_riscv_add_f32(void);

int main(void)
{
    printf("Start benchmark/BasicMathFunctions/add_riscv_add_f32\n");
    printf("RUN add_riscv_add_f32\n");
    add_riscv_add_f32();
    printf("PASS benchmark/BasicMathFunctions/add_riscv_add_f32 count=%d\n", 1);
    return 0;
}
