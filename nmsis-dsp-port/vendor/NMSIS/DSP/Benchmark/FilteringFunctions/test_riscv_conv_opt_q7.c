#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ConvolutionFunctions/conv_opt_q7/test_data.h"

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


void conv_riscv_conv_opt_q7(void)
{
    q7_t conv_opt_q7_output[2 * max(ARRAYA_SIZE_Q7, ARRAYB_SIZE_Q7)];

    generate_rand_q7(test_conv_input_q7_A, ARRAYA_SIZE_Q7);
    generate_rand_q7(test_conv_input_q7_B, ARRAYB_SIZE_Q7);

    BENCH_START(riscv_conv_opt_q7);
    riscv_conv_opt_q7(test_conv_input_q7_A, ARRAYA_SIZE_Q7, test_conv_input_q7_B, ARRAYB_SIZE_Q7,
                    conv_opt_q7_output, pScratch1, pScratch2);
    BENCH_END(riscv_conv_opt_q7);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, conv_opt_q7_output, (uint32_t)sizeof(conv_opt_q7_output));
    printf("@@RESULT@@ case=conv_riscv_conv_opt_q7 hash=0x%08x\n", (unsigned int)__zr_hash);
}