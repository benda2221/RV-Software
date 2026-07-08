#include <stdio.h>
extern void cmplx_mag_squared_riscv_cmplx_mag_squared_f32(void);

int main(void)
{
    printf("Start benchmark/ComplexMathFunctions/cmplx_mag_squared_riscv_cmplx_mag_squared_f32\n");
    printf("RUN cmplx_mag_squared_riscv_cmplx_mag_squared_f32\n");
    cmplx_mag_squared_riscv_cmplx_mag_squared_f32();
    printf("PASS benchmark/ComplexMathFunctions/cmplx_mag_squared_riscv_cmplx_mag_squared_f32 count=%d\n", 1);
    return 0;
}
