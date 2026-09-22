#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/QuaternionMathFunctions/quaternion_normalize_f32/test_data.h"

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


void quaternionNormalize_riscv_quaternion_normalize_f32(void)
{
    float32_t f32_output[4 * ARRAY_SIZE];

    generate_rand_f32(quat_normaliza_f32_input, 4 * ARRAY_SIZE);

    
    zircon_result_zero_f32(f32_output, (uint32_t)(sizeof(f32_output) / sizeof(f32_output[0])));
BENCH_START(riscv_quaternion_normalize_f32);
    riscv_quaternion_normalize_f32(quat_normaliza_f32_input, f32_output, ARRAY_SIZE);
    BENCH_END(riscv_quaternion_normalize_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_output, (uint32_t)sizeof(f32_output));
    printf("@@RESULT@@ case=quaternionNormalize_riscv_quaternion_normalize_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}
