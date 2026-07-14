#include <stdio.h>
extern void sin_cos_riscv_sin_cos_q31(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/sin_cos_riscv_sin_cos_q31\n");
    printf("RUN sin_cos_riscv_sin_cos_q31\n");
    sin_cos_riscv_sin_cos_q31();
    printf("PASS benchmark/ControllerFunctions/sin_cos_riscv_sin_cos_q31 count=%d\n", 1);
    return 0;
}
