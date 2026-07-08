#include <stdio.h>
extern void clarke_riscv_clarke_f32(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/clarke_riscv_clarke_f32\n");
    printf("RUN clarke_riscv_clarke_f32\n");
    clarke_riscv_clarke_f32();
    printf("PASS benchmark/ControllerFunctions/clarke_riscv_clarke_f32 count=%d\n", 1);
    return 0;
}
