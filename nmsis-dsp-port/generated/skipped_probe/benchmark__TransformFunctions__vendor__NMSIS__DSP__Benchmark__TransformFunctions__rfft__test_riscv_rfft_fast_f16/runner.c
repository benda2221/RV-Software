#include <stdio.h>
extern void rfft_riscv_rfft_fast_f16(void);

int main(void)
{
    printf("Start skipped-probe/benchmark__TransformFunctions__vendor__NMSIS__DSP__Benchmark__TransformFunctions__rfft__test_riscv_rfft_fast_f16\n");
    printf("RUN rfft_riscv_rfft_fast_f16\n");
    rfft_riscv_rfft_fast_f16();
    printf("PASS skipped-probe/benchmark__TransformFunctions__vendor__NMSIS__DSP__Benchmark__TransformFunctions__rfft__test_riscv_rfft_fast_f16 count=%d\n", 1);
    return 0;
}
