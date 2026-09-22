#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ConvolutionFunctions/conv_q31/test_data.h"

BENCH_DECLARE_VAR();

static uint32_t zircon_result_hash_combine(uint32_t hash, const void *data, uint32_t length)
{
    const uint8_t *bytes = (const uint8_t *)data;

    for (uint32_t i = 0; i < length; i++) {
        hash ^= bytes[i];
        hash *= 16777619u;
    }

    return hash;
}


void conv_riscv_conv_fast_q31(void)
{
    q31_t conv_fast_q31_output[2 * max(ARRAYA_SIZE_Q31, ARRAYB_SIZE_Q31)];

    generate_rand_q31(test_conv_input_q31_A, ARRAYA_SIZE_Q31);
    generate_rand_q31(test_conv_input_q31_B, ARRAYB_SIZE_Q31);

    BENCH_START(riscv_conv_fast_q31);
    riscv_conv_fast_q31(test_conv_input_q31_A, ARRAYA_SIZE_Q31, test_conv_input_q31_B, ARRAYB_SIZE_Q31,
                      conv_fast_q31_output);
    BENCH_END(riscv_conv_fast_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, conv_fast_q31_output, (uint32_t)((ARRAYA_SIZE_Q31 + ARRAYB_SIZE_Q31 - 1u) * sizeof(conv_fast_q31_output[0])));
    printf("@@RESULT@@ case=conv_riscv_conv_fast_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}