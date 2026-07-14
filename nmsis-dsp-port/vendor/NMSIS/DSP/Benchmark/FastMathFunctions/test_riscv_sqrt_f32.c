#include "riscv_math.h"
#include <stdio.h>
#include <stdlib.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FastMathFunctions/sqrt_f32/test_data.h"

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

static void zircon_result_zero_f32(float32_t *data, uint32_t length)
{
    for (uint32_t i = 0; i < length; i++) {
        data[i] = 0.0f;
    }
}


void sqrt_riscv_sqrt_f32(void)
{
    float32_t sqrt_f32_output[ARRAY_SIZE_F32];

    do_srand();
    for (int i = 0; i < ARRAY_SIZE_F32; i++) {
        sqrt_f32_input[i] = (float32_t)((rand() % Q31_MAX - Q31_MAX / 2) * 1.0 / Q31_MAX);
        sqrt_f32_input[i] = sqrt_f32_input[i] > 0.0f ? sqrt_f32_input[i] : 0.01f;
    }

    riscv_status result;
    
    zircon_result_zero_f32(sqrt_f32_output, (uint32_t)(sizeof(sqrt_f32_output) / sizeof(sqrt_f32_output[0])));
BENCH_START(riscv_sqrt_f32);
    for (volatile int i = 0; i < ARRAY_SIZE_F32; i++) {
        result = riscv_sqrt_f32(sqrt_f32_input[i], &sqrt_f32_output[i]);
    }
    BENCH_END(riscv_sqrt_f32);

    
    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, sqrt_f32_output, (uint32_t)sizeof(sqrt_f32_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, sqrt_f32_input, (uint32_t)sizeof(sqrt_f32_input));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=sqrt_riscv_sqrt_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);

    return;
}
