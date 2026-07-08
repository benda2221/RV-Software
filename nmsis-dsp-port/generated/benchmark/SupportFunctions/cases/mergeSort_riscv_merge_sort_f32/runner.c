#include <stdio.h>
extern void mergeSort_riscv_merge_sort_f32(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/mergeSort_riscv_merge_sort_f32\n");
    printf("RUN mergeSort_riscv_merge_sort_f32\n");
    mergeSort_riscv_merge_sort_f32();
    printf("PASS benchmark/SupportFunctions/mergeSort_riscv_merge_sort_f32 count=%d\n", 1);
    return 0;
}
