#include <stdio.h>
extern void bilinear_riscv_bilinear_interp_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__InterpolationFunctions__vendor__NMSIS__DSP__Benchmark__InterpolationFunctions__test_riscv_bilinear_interp_f16\n");
    printf("RUN bilinear_riscv_bilinear_interp_f16\n");
    bilinear_riscv_bilinear_interp_f16();
    printf("PASS skipped-probe/benchmark__InterpolationFunctions__vendor__NMSIS__DSP__Benchmark__InterpolationFunctions__test_riscv_bilinear_interp_f16 count=%d\n", 1);
    return 0;
}
