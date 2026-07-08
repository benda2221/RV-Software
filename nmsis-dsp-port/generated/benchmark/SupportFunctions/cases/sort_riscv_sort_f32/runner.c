#include <stdio.h>
extern void sort_riscv_sort_f32(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/sort_riscv_sort_f32\n");
    printf("RUN sort_riscv_sort_f32\n");
    sort_riscv_sort_f32();
    printf("PASS benchmark/SupportFunctions/sort_riscv_sort_f32 count=%d\n", 1);
    return 0;
}
