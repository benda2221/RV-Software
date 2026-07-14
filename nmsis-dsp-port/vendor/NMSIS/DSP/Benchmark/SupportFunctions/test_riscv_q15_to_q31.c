#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/SupportFunctions/q15_to_q31/test_data.h"

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


void q15ToQ31_riscv_q15_to_q31(void)
{
    q31_t q31_output[ARRAY_SIZE];

    generate_rand_q15(q15_input, ARRAY_SIZE);

    BENCH_START(riscv_q15_to_q31);
    riscv_q15_to_q31(q15_input, q31_output, ARRAY_SIZE);
    BENCH_END(riscv_q15_to_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, q31_output, (uint32_t)sizeof(q31_output));
    printf("@@RESULT@@ case=q15ToQ31_riscv_q15_to_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}