#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/negate_q31/test_data.h"

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


void negate_riscv_negate_q31(void)
{
    q31_t negate_q31_output[ARRAY_SIZE_Q31];

    generate_rand_q31(negate_q31_input, ARRAY_SIZE_Q31);

    // q31_mult
    BENCH_START(riscv_negate_q31);
    riscv_negate_q31(negate_q31_input, negate_q31_output, ARRAY_SIZE_Q31);
    BENCH_END(riscv_negate_q31);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, negate_q31_output, (uint32_t)sizeof(negate_q31_output));
    printf("@@RESULT@@ case=negate_riscv_negate_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}