#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FastMathFunctions/cos_q15/test_data.h"

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


void cos_riscv_cos_q15(void)
{
    q15_t cos_q15_output[ARRAY_SIZE_Q15];
    
    generate_rand_q15(cos_q15_input, ARRAY_SIZE_Q15);

    BENCH_START(riscv_cos_q15);
    for (int i = 0; i < ARRAY_SIZE_Q15; i++) {
        cos_q15_output[i] = riscv_cos_q15(cos_q15_input[i]);
    }
    BENCH_END(riscv_cos_q15);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, cos_q15_output, (uint32_t)sizeof(cos_q15_output));
    printf("@@RESULT@@ case=cos_riscv_cos_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}