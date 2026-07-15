#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/fir_sparse_f32/test_data.h"

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


void firSparse_riscv_fir_sparse_f32(void)
{
    float32_t firStatef32[TEST_LENGTH_SAMPLES + NUM_TAPS - 1];
    float32_t fir_sparse_f32_output[TEST_LENGTH_SAMPLES];

    generate_rand_f32(testInput_f32_50Hz_200Hz, TEST_LENGTH_SAMPLES);
    /* clang-format off */
    riscv_fir_sparse_instance_f32 S;
    /* clang-format on */
    for (int i = 0; i < NUM_TAPS; i++) {
        pTapDelay[i] = i + 1;
    }

    riscv_fir_sparse_init_f32(&S, NUM_TAPS, firCoeffs32LP, firStatef32, pTapDelay, MAXDelay, TEST_LENGTH_SAMPLES);
    
    zircon_result_zero_f32(firStatef32, (uint32_t)(sizeof(firStatef32) / sizeof(firStatef32[0])));
    zircon_result_zero_f32(fir_sparse_f32_output, (uint32_t)(sizeof(fir_sparse_f32_output) / sizeof(fir_sparse_f32_output[0])));
BENCH_START(riscv_fir_sparse_f32);
    riscv_fir_sparse_f32(&S, testInput_f32_50Hz_200Hz, fir_sparse_f32_output, pTapDelayScratch_f32, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_fir_sparse_f32);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, fir_sparse_f32_output, (uint32_t)sizeof(fir_sparse_f32_output));
    printf("@@RESULT@@ case=firSparse_riscv_fir_sparse_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}
