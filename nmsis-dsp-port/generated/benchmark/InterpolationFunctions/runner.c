#include <stdio.h>
extern void bilinear_riscv_bilinear_interp_f32(void);
extern void bilinear_riscv_bilinear_interp_q15(void);
extern void bilinear_riscv_bilinear_interp_q31(void);
extern void bilinear_riscv_bilinear_interp_q7(void);
extern void linear_riscv_linear_interp_f32(void);
extern void linear_riscv_linear_interp_q15(void);
extern void linear_riscv_linear_interp_q31(void);
extern void linear_riscv_linear_interp_q7(void);
extern void spline_riscv_spline_f32(void);

int main(void)
{
    printf("Start benchmark/InterpolationFunctions\n");
    printf("RUN bilinear_riscv_bilinear_interp_f32\n");
    bilinear_riscv_bilinear_interp_f32();
    printf("RUN bilinear_riscv_bilinear_interp_q15\n");
    bilinear_riscv_bilinear_interp_q15();
    printf("RUN bilinear_riscv_bilinear_interp_q31\n");
    bilinear_riscv_bilinear_interp_q31();
    printf("RUN bilinear_riscv_bilinear_interp_q7\n");
    bilinear_riscv_bilinear_interp_q7();
    printf("RUN linear_riscv_linear_interp_f32\n");
    linear_riscv_linear_interp_f32();
    printf("RUN linear_riscv_linear_interp_q15\n");
    linear_riscv_linear_interp_q15();
    printf("RUN linear_riscv_linear_interp_q31\n");
    linear_riscv_linear_interp_q31();
    printf("RUN linear_riscv_linear_interp_q7\n");
    linear_riscv_linear_interp_q7();
    printf("RUN spline_riscv_spline_f32\n");
    spline_riscv_spline_f32();
    printf("PASS benchmark/InterpolationFunctions count=%d\n", 9);
    return 0;
}
