#include <stdio.h>
extern void clarke_riscv_clarke_q31(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/clarke_riscv_clarke_q31\n");
    printf("RUN clarke_riscv_clarke_q31\n");
    clarke_riscv_clarke_q31();
    printf("PASS benchmark/ControllerFunctions/clarke_riscv_clarke_q31 count=%d\n", 1);
    return 0;
}
