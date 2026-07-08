#include <stdio.h>
extern void inv_clarke_riscv_inv_clarke_f32(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/inv_clarke_riscv_inv_clarke_f32\n");
    printf("RUN inv_clarke_riscv_inv_clarke_f32\n");
    inv_clarke_riscv_inv_clarke_f32();
    printf("PASS benchmark/ControllerFunctions/inv_clarke_riscv_inv_clarke_f32 count=%d\n", 1);
    return 0;
}
