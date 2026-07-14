#include <stdio.h>
extern void inv_park_riscv_inv_park_q31(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/inv_park_riscv_inv_park_q31\n");
    printf("RUN inv_park_riscv_inv_park_q31\n");
    inv_park_riscv_inv_park_q31();
    printf("PASS benchmark/ControllerFunctions/inv_park_riscv_inv_park_q31 count=%d\n", 1);
    return 0;
}
