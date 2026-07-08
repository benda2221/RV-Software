#include <stdio.h>
extern void clarke_riscv_clarke_f32(void);
extern void clarke_riscv_clarke_q31(void);
extern void inv_clarke_riscv_inv_clarke_f32(void);
extern void inv_clarke_riscv_inv_clarke_q31(void);
extern void inv_park_riscv_inv_park_f32(void);
extern void park_riscv_park_f32(void);
extern void pid_riscv_pid_f32(void);

int main(void)
{
    printf("Start benchmark/ControllerFunctions\n");
    printf("RUN clarke_riscv_clarke_f32\n");
    clarke_riscv_clarke_f32();
    printf("RUN clarke_riscv_clarke_q31\n");
    clarke_riscv_clarke_q31();
    printf("RUN inv_clarke_riscv_inv_clarke_f32\n");
    inv_clarke_riscv_inv_clarke_f32();
    printf("RUN inv_clarke_riscv_inv_clarke_q31\n");
    inv_clarke_riscv_inv_clarke_q31();
    printf("RUN inv_park_riscv_inv_park_f32\n");
    inv_park_riscv_inv_park_f32();
    printf("RUN park_riscv_park_f32\n");
    park_riscv_park_f32();
    printf("RUN pid_riscv_pid_f32\n");
    pid_riscv_pid_f32();
    printf("PASS benchmark/ControllerFunctions count=%d\n", 7);
    return 0;
}
