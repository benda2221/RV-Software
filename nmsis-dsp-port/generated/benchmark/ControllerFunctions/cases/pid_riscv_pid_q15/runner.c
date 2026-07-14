#include <stdio.h>
extern void pid_riscv_pid_q15(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/pid_riscv_pid_q15\n");
    printf("RUN pid_riscv_pid_q15\n");
    pid_riscv_pid_q15();
    printf("PASS benchmark/ControllerFunctions/pid_riscv_pid_q15 count=%d\n", 1);
    return 0;
}
