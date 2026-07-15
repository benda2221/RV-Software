
#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ConvolutionFunctions/conv_partial_q15/test_data.h"

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


void convPartial_riscv_conv_partial_fast_q15(void)
{
    q15_t conv_partial_fast_q15_output[2 * max(ARRAYA_SIZE_Q15, ARRAYB_SIZE_Q15)];

    generate_rand_q15(test_conv_input_q15_A, ARRAYA_SIZE_Q15);
    generate_rand_q15(test_conv_input_q15_B, ARRAYB_SIZE_Q15);

    BENCH_START(riscv_conv_partial_fast_q15);
    riscv_status result = riscv_conv_partial_fast_q15(test_conv_input_q15_A, ARRAYA_SIZE_Q15, test_conv_input_q15_B,
                              ARRAYB_SIZE_Q15, conv_partial_fast_q15_output, firstIndex, numPoints);
    BENCH_END(riscv_conv_partial_fast_q15);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, conv_partial_fast_q15_output, (uint32_t)sizeof(conv_partial_fast_q15_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=convPartial_riscv_conv_partial_fast_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);

    return;
}