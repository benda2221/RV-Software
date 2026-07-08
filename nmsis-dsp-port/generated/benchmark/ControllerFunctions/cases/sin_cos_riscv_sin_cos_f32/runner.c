#include <stdio.h>
extern void sin_cos_riscv_sin_cos_f32(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/sin_cos_riscv_sin_cos_f32\n");
    printf("RUN sin_cos_riscv_sin_cos_f32\n");
    sin_cos_riscv_sin_cos_f32();
    printf("PASS benchmark/ControllerFunctions/sin_cos_riscv_sin_cos_f32 count=%d\n", 1);
    return 0;
}
