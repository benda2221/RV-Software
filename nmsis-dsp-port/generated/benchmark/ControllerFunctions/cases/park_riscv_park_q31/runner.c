#include <stdio.h>
extern void park_riscv_park_q31(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/park_riscv_park_q31\n");
    printf("RUN park_riscv_park_q31\n");
    park_riscv_park_q31();
    printf("PASS benchmark/ControllerFunctions/park_riscv_park_q31 count=%d\n", 1);
    return 0;
}
