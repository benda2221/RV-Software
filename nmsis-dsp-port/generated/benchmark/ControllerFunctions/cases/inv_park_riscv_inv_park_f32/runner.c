#include <stdio.h>
extern void inv_park_riscv_inv_park_f32(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/inv_park_riscv_inv_park_f32\n");
    printf("RUN inv_park_riscv_inv_park_f32\n");
    inv_park_riscv_inv_park_f32();
    printf("PASS benchmark/ControllerFunctions/inv_park_riscv_inv_park_f32 count=%d\n", 1);
    return 0;
}
