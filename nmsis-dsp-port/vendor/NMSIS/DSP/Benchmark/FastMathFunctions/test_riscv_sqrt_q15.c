#include "riscv_math.h"
#include <stdio.h>
#include <stdlib.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FastMathFunctions/sqrt_q15/test_data.h"

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


void sqrt_riscv_sqrt_q15(void)
{
    q15_t sqrt_q15_output[ARRAY_SIZE_Q15];

    do_srand();
    for (int i = 0; i < ARRAY_SIZE_Q15; i++) {
        sqrt_q15_input[i] = (q15_t)(rand() % Q15_MAX - Q15_MAX / 2);
        sqrt_q15_input[i] = sqrt_q15_input[i] > 0 ? sqrt_q15_input[i] : 10;
    }

    riscv_status result;
    BENCH_START(riscv_sqrt_q15);
    for (int i = 0; i < ARRAY_SIZE_Q15; i++) {
        result = riscv_sqrt_q15(sqrt_q15_input[i], &sqrt_q15_output[i]);
    }
    BENCH_END(riscv_sqrt_q15);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, sqrt_q15_output, (uint32_t)sizeof(sqrt_q15_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=sqrt_riscv_sqrt_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);

    return;
}
