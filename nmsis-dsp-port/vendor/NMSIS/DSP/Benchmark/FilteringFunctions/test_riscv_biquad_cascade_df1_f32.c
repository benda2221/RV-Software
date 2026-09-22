#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/biquad_cascade_df1_f32/test_data.h"

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

void df1_riscv_biquad_cascade_df1_f32(void)
{
    float32_t biquad_cascade_df1_f32_output[TEST_LENGTH_SAMPLES];
    float32_t IIRStateF32[4 * numStages];

    riscv_biquad_casd_df1_inst_f32 S;
    generate_rand_f32(testInput_f32_50Hz_200Hz, TEST_LENGTH_SAMPLES);

    riscv_biquad_cascade_df1_init_f32(&S, numStages, IIRCoeffs32LP, IIRStateF32);
    
    zircon_result_zero_f32(biquad_cascade_df1_f32_output, (uint32_t)(sizeof(biquad_cascade_df1_f32_output) / sizeof(biquad_cascade_df1_f32_output[0])));
    zircon_result_zero_f32(IIRStateF32, (uint32_t)(sizeof(IIRStateF32) / sizeof(IIRStateF32[0])));
BENCH_START(riscv_biquad_cascade_df1_f32);
    riscv_biquad_cascade_df1_f32(&S, testInput_f32_50Hz_200Hz, biquad_cascade_df1_f32_output, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_biquad_cascade_df1_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, biquad_cascade_df1_f32_output, (uint32_t)sizeof(biquad_cascade_df1_f32_output));
    printf("@@RESULT@@ case=df1_riscv_biquad_cascade_df1_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}