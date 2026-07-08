#include <stdio.h>
extern void fill_riscv_fill_f32(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/fill_riscv_fill_f32\n");
    printf("RUN fill_riscv_fill_f32\n");
    fill_riscv_fill_f32();
    printf("PASS benchmark/SupportFunctions/fill_riscv_fill_f32 count=%d\n", 1);
    return 0;
}
