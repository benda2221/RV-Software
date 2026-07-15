#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FastMathFunctions/atan2_f32/test_data.h"

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


void atan2_riscv_atan2_f32(void)
{
    float32_t atan2_f32_output[ARRAY_SIZE_F32];

    generate_rand_f32(atan2_f32_input1, ARRAY_SIZE_F32);
    generate_rand_f32(atan2_f32_input2, ARRAY_SIZE_F32);

    riscv_status result;
    
    zircon_result_zero_f32(atan2_f32_output, (uint32_t)(sizeof(atan2_f32_output) / sizeof(atan2_f32_output[0])));
BENCH_START(riscv_atan2_f32);
    for (int i = 0; i < ARRAY_SIZE_F32; i++) {
        result = riscv_atan2_f32(atan2_f32_input1[i], atan2_f32_input2[i], &atan2_f32_output[i]);
    }
    BENCH_END(riscv_atan2_f32);

    



    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, atan2_f32_output, (uint32_t)sizeof(atan2_f32_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=atan2_riscv_atan2_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);

    return;
}
