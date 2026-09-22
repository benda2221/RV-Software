#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ConvolutionFunctions/conv_f32/test_data.h"

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


void conv_riscv_conv_f32(void)
{
    float32_t conv_f32_output[2 * max(ARRAYA_SIZE_F32, ARRAYB_SIZE_F32)];

    generate_rand_f32(test_conv_input_f32_A, ARRAYA_SIZE_F32);
    generate_rand_f32(test_conv_input_f32_B, ARRAYB_SIZE_F32);

    
    zircon_result_zero_f32(conv_f32_output, (uint32_t)(sizeof(conv_f32_output) / sizeof(conv_f32_output[0])));
BENCH_START(riscv_conv_f32);
    riscv_conv_f32(test_conv_input_f32_A, ARRAYA_SIZE_F32, test_conv_input_f32_B, ARRAYB_SIZE_F32,
                 conv_f32_output);
    BENCH_END(riscv_conv_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, conv_f32_output, (uint32_t)((ARRAYA_SIZE_F32 + ARRAYB_SIZE_F32 - 1u) * sizeof(conv_f32_output[0])));
    printf("@@RESULT@@ case=conv_riscv_conv_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
