#include <stdio.h>
extern void pid_riscv_pid_q15(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__ControllerFunctions__vendor__NMSIS__DSP__Benchmark__ControllerFunctions__test_riscv_pid_q15\n");
    printf("RUN pid_riscv_pid_q15\n");
    pid_riscv_pid_q15();
    printf("PASS skipped-probe/benchmark__ControllerFunctions__vendor__NMSIS__DSP__Benchmark__ControllerFunctions__test_riscv_pid_q15 count=%d\n", 1);
    return 0;
}
