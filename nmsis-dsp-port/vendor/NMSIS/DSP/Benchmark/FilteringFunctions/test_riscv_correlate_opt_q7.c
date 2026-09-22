#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ConvolutionFunctions/correlate_opt_q7/test_data.h"

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


void correlate_riscv_correlate_opt_q7(void)
{
    q7_t correlate_q7_output[2 * max(ARRAYA_SIZE_Q7, ARRAYB_SIZE_Q7)];

    generate_rand_q7(correlate_input_q7_A, ARRAYA_SIZE_Q7);
    generate_rand_q7(correlate_input_q7_B, ARRAYB_SIZE_Q7);

    BENCH_START(riscv_correlate_opt_q7);
    riscv_correlate_opt_q7(correlate_input_q7_A, ARRAYA_SIZE_Q7, correlate_input_q7_B, ARRAYB_SIZE_Q7,
                          correlate_q7_output, q15_pScratch1, q15_pScratch2);
    BENCH_END(riscv_correlate_opt_q7);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, correlate_q7_output + ((ARRAYA_SIZE_Q7 >= ARRAYB_SIZE_Q7) ? (ARRAYA_SIZE_Q7 - ARRAYB_SIZE_Q7) : 0u), (uint32_t)((ARRAYA_SIZE_Q7 + ARRAYB_SIZE_Q7 - 1u) * sizeof(correlate_q7_output[0])));
    printf("@@RESULT@@ case=correlate_riscv_correlate_opt_q7 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
