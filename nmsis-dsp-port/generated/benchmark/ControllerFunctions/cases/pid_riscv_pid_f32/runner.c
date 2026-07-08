#include <stdio.h>
extern void pid_riscv_pid_f32(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions/pid_riscv_pid_f32\n");
    printf("RUN pid_riscv_pid_f32\n");
    pid_riscv_pid_f32();
    printf("PASS benchmark/ControllerFunctions/pid_riscv_pid_f32 count=%d\n", 1);
    return 0;
}
