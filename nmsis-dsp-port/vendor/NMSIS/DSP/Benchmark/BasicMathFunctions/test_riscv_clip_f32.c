#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/clip_f32/test_data.h"

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

void clip_riscv_clip_f32(void)
{
    float32_t low_f32 = LOWER_BOUND_F32;
    float32_t high_f32 = HIGHER_BOUND_F32;
    float32_t clip_f32_output[ARRAY_SIZE_F32];

    generate_rand_f32(clip_f32_input, ARRAY_SIZE_F32);

    
    zircon_result_zero_f32(clip_f32_output, (uint32_t)(sizeof(clip_f32_output) / sizeof(clip_f32_output[0])));
BENCH_START(riscv_clip_f32);
    riscv_clip_f32(clip_f32_input, clip_f32_output, low_f32, high_f32, ARRAY_SIZE_F32);
    BENCH_END(riscv_clip_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, clip_f32_output, (uint32_t)sizeof(clip_f32_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, clip_f32_input, (uint32_t)sizeof(clip_f32_input));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &low_f32, (uint32_t)sizeof(low_f32));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &high_f32, (uint32_t)sizeof(high_f32));
    printf("@@RESULT@@ case=clip_riscv_clip_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}