#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/abs_q15/test_data.h"

BENCH_DECLARE_VAR();

static uint32_t checksum_q15(const q15_t *data, uint32_t length)
{
    uint32_t checksum = 2166136261u;

    for (uint32_t i = 0; i < length; i++) {
        uint16_t value = (uint16_t)data[i];
        checksum ^= value & 0xffu;
        checksum *= 16777619u;
        checksum ^= value >> 8;
        checksum *= 16777619u;
    }

    return checksum;
}

void abs_riscv_abs_q15(void)
{
    
    q15_t abs_q15_output[ARRAY_SIZE_Q15];
    
    generate_rand_q15(abs_q15_input, ARRAY_SIZE_Q15);

    // riscv_abs_q15.c
    BENCH_START(riscv_abs_q15);
    riscv_abs_q15(abs_q15_input, abs_q15_output, ARRAY_SIZE_Q15);
    BENCH_END(riscv_abs_q15);

    printf("@@RESULT@@ case=riscv_abs_q15 count=%u checksum=0x%08x first=%d second=%d last=%d\n",
           (unsigned int)ARRAY_SIZE_Q15,
           (unsigned int)checksum_q15(abs_q15_output, ARRAY_SIZE_Q15),
           abs_q15_output[0],
           abs_q15_output[1],
           abs_q15_output[ARRAY_SIZE_Q15 - 1]);

    return;
}
