#include <stdio.h>
extern void pid_riscv_pid_q31(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/pid_riscv_pid_q31\n");
    printf("RUN pid_riscv_pid_q31\n");
    pid_riscv_pid_q31();
    printf("PASS benchmark/ControllerFunctions/pid_riscv_pid_q31 count=%d\n", 1);
    return 0;
}
