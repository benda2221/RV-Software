#include <stdio.h>
extern void copy_riscv_copy_f32(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/copy_riscv_copy_f32\n");
    printf("RUN copy_riscv_copy_f32\n");
    copy_riscv_copy_f32();
    printf("PASS benchmark/SupportFunctions/copy_riscv_copy_f32 count=%d\n", 1);
    return 0;
}
