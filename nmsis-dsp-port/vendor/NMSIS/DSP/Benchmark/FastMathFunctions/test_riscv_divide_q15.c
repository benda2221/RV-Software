#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FastMathFunctions/divide_q15/test_data.h"

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


void divide_riscv_divide_q15(void)
{
    q15_t divide_q15_output[ARRAY_SIZE_Q15];
    int16_t shift_i16[ARRAY_SIZE_Q15];

    generate_rand_q15(divide_q15_input1, ARRAY_SIZE_Q15);
    generate_rand_q15(divide_q15_input2, ARRAY_SIZE_Q15);

    riscv_status result;
    BENCH_START(riscv_divide_q15);
    for (int i = 0; i < ARRAY_SIZE_Q15; i++) {
        result = riscv_divide_q15(divide_q15_input1[i], divide_q15_input2[i], &divide_q15_output[i], &shift_i16[i]);
    }
    BENCH_END(riscv_divide_q15);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, divide_q15_output, (uint32_t)sizeof(divide_q15_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=divide_riscv_divide_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);

    return;
}
