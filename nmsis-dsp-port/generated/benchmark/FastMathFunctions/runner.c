#include <stdio.h>
extern void atan2_riscv_atan2_q15(void);
extern void atan2_riscv_atan2_q31(void);
extern void cos_riscv_cos_q15(void);
extern void cos_riscv_cos_q31(void);
extern void divide_riscv_divide_q15(void);
extern void divide_riscv_divide_q31(void);
extern void sqrt_riscv_sqrt_q15(void);
extern void sqrt_riscv_sqrt_q31(void);
extern void vlog_riscv_vlog_q15(void);
extern void vlog_riscv_vlog_q31(void);

int main(void)
{
    printf("Start benchmark/FastMathFunctions\n");
    printf("RUN atan2_riscv_atan2_q15\n");
    atan2_riscv_atan2_q15();
    printf("RUN atan2_riscv_atan2_q31\n");
    atan2_riscv_atan2_q31();
    printf("RUN cos_riscv_cos_q15\n");
    cos_riscv_cos_q15();
    printf("RUN cos_riscv_cos_q31\n");
    cos_riscv_cos_q31();
    printf("RUN divide_riscv_divide_q15\n");
    divide_riscv_divide_q15();
    printf("RUN divide_riscv_divide_q31\n");
    divide_riscv_divide_q31();
    printf("RUN sqrt_riscv_sqrt_q15\n");
    sqrt_riscv_sqrt_q15();
    printf("RUN sqrt_riscv_sqrt_q31\n");
    sqrt_riscv_sqrt_q31();
    printf("RUN vlog_riscv_vlog_q15\n");
    vlog_riscv_vlog_q15();
    printf("RUN vlog_riscv_vlog_q31\n");
    vlog_riscv_vlog_q31();
    printf("PASS benchmark/FastMathFunctions count=%d\n", 10);
    return 0;
}
