#include <stdio.h>
extern void barycenter_riscv_barycenter_f32(void);

int main(void)
{
    printf("Start benchmark/SupportFunctions/barycenter_riscv_barycenter_f32\n");
    printf("RUN barycenter_riscv_barycenter_f32\n");
    barycenter_riscv_barycenter_f32();
    printf("PASS benchmark/SupportFunctions/barycenter_riscv_barycenter_f32 count=%d\n", 1);
    return 0;
}
