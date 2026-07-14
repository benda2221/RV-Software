#include <stdio.h>
extern void lms_riscv_lms_f32(void);

int main(void)
{
    printf("Start benchmark/FilteringFunctions/lms_riscv_lms_f32\n");
    printf("RUN lms_riscv_lms_f32\n");
    lms_riscv_lms_f32();
    printf("PASS benchmark/FilteringFunctions/lms_riscv_lms_f32 count=%d\n", 1);
    return 0;
}
