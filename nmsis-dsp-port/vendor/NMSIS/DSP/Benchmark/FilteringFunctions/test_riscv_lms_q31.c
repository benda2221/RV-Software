#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/lms_q31/test_data.h"

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


void lms_riscv_lms_q31(void)
{
    q31_t error_ones_q31[TEST_LENGTH_SAMPLES];
    q31_t lms_q31_output[TEST_LENGTH_SAMPLES];
    q31_t firStateQ31_LMS[TEST_LENGTH_SAMPLES + NUM_TAPS - 1];

    generate_rand_q31(testInput_q31_50Hz_200Hz, TEST_LENGTH_SAMPLES);
    generate_rand_q31(expectoutput_q31_50Hz_200Hz, TEST_LENGTH_SAMPLES);
    float32_t firCoeffs32LP[NUM_TAPS];
    for (int i = 0; i < NUM_TAPS; i++) {
        firCoeffs32LP[i] = (float32_t)rand() / RAND_MAX * 2 - 1;
    }
    riscv_float_to_q31(firCoeffs32LP, firCoeffs32LP_q31, NUM_TAPS);

    /* clang-format off */
    riscv_lms_instance_q31 S;
    riscv_lms_init_q31(&S, NUM_TAPS, firCoeffs32LP_q31, firStateQ31_LMS, MU_SIZE_Q31, TEST_LENGTH_SAMPLES, 1);
    BENCH_START(riscv_lms_q31);
    riscv_lms_q31(&S, testInput_q31_50Hz_200Hz, expectoutput_q31_50Hz_200Hz, lms_q31_output, error_ones_q31, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_lms_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, error_ones_q31, (uint32_t)sizeof(error_ones_q31));
    __zr_hash = zircon_result_hash_combine(__zr_hash, lms_q31_output, (uint32_t)sizeof(lms_q31_output));
    printf("@@RESULT@@ case=lms_riscv_lms_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}
