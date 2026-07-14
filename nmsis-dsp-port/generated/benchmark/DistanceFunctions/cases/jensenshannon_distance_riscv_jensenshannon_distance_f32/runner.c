#include <stdio.h>
extern void jensenshannon_distance_riscv_jensenshannon_distance_f32(void);

int main(void)
{
    printf("Start benchmark/DistanceFunctions/jensenshannon_distance_riscv_jensenshannon_distance_f32\n");
    printf("RUN jensenshannon_distance_riscv_jensenshannon_distance_f32\n");
    jensenshannon_distance_riscv_jensenshannon_distance_f32();
    printf("PASS benchmark/DistanceFunctions/jensenshannon_distance_riscv_jensenshannon_distance_f32 count=%d\n", 1);
    return 0;
}
