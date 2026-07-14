#include <stdio.h>
extern void cfft_riscv_cfft_radix4_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__TransformFunctions__vendor__NMSIS__DSP__Benchmark__TransformFunctions__cfft__test_riscv_cfft_radix4_f16\n");
    printf("RUN cfft_riscv_cfft_radix4_f16\n");
    cfft_riscv_cfft_radix4_f16();
    printf("PASS skipped-probe/benchmark__TransformFunctions__vendor__NMSIS__DSP__Benchmark__TransformFunctions__cfft__test_riscv_cfft_radix4_f16 count=%d\n", 1);
    return 0;
}
