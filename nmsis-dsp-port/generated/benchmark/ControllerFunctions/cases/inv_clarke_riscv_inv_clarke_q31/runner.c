#include <stdio.h>
extern void inv_clarke_riscv_inv_clarke_q31(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/inv_clarke_riscv_inv_clarke_q31\n");
    printf("RUN inv_clarke_riscv_inv_clarke_q31\n");
    inv_clarke_riscv_inv_clarke_q31();
    printf("PASS benchmark/ControllerFunctions/inv_clarke_riscv_inv_clarke_q31 count=%d\n", 1);
    return 0;
}
