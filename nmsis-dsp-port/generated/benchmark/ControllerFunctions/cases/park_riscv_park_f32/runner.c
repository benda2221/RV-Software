#include <stdio.h>
extern void park_riscv_park_f32(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/park_riscv_park_f32\n");
    printf("RUN park_riscv_park_f32\n");
    park_riscv_park_f32();
    printf("PASS benchmark/ControllerFunctions/park_riscv_park_f32 count=%d\n", 1);
    return 0;
}
