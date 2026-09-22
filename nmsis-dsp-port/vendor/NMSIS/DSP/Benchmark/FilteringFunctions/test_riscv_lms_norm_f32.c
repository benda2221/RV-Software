#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/lms_norm_f32/test_data.h"

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


void lmsNorm_riscv_lms_norm_f32(void)
{
    float32_t error_ones[TEST_LENGTH_SAMPLES];
    float32_t lms_norm_f32_output[TEST_LENGTH_SAMPLES];
    float32_t firStateF32_LMS[TEST_LENGTH_SAMPLES + NUM_TAPS - 1];

    generate_rand_f32(testInput_f32_50Hz_200Hz, TEST_LENGTH_SAMPLES);
    generate_rand_f32(expectoutput_f32_50Hz_200Hz, TEST_LENGTH_SAMPLES);

    for (int i = 0; i < NUM_TAPS; i++) {
        firCoeffs32LP[i] = (float32_t)rand() / RAND_MAX * 2 - 1;
    }

    /* clang-format off */
    riscv_lms_norm_instance_f32 S;

    riscv_lms_norm_init_f32(&S, NUM_TAPS, firCoeffs32LP, firStateF32_LMS, MU_SIZE, TEST_LENGTH_SAMPLES);
    
    zircon_result_zero_f32(error_ones, (uint32_t)(sizeof(error_ones) / sizeof(error_ones[0])));
    zircon_result_zero_f32(lms_norm_f32_output, (uint32_t)(sizeof(lms_norm_f32_output) / sizeof(lms_norm_f32_output[0])));
    zircon_result_zero_f32(firStateF32_LMS, (uint32_t)(sizeof(firStateF32_LMS) / sizeof(firStateF32_LMS[0])));
BENCH_START(riscv_lms_norm_f32);
    riscv_lms_norm_f32(&S, testInput_f32_50Hz_200Hz, expectoutput_f32_50Hz_200Hz, lms_norm_f32_output, error_ones, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_lms_norm_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, error_ones, (uint32_t)sizeof(error_ones));
    __zr_hash = zircon_result_hash_combine(__zr_hash, lms_norm_f32_output, (uint32_t)sizeof(lms_norm_f32_output));
    printf("@@RESULT@@ case=lmsNorm_riscv_lms_norm_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}
