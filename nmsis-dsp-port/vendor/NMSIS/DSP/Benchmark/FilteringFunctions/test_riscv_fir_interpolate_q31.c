#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/fir_interpolate_q31/test_data.h"

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


void firInterpolate_riscv_fir_interpolate_q31(void)
{
    q31_t firStateq31[TEST_LENGTH_SAMPLES + NUM_TAPS - 1];
    q31_t interpolate_q31_output[TEST_LENGTH_SAMPLES];

    generate_rand_q31(testInput_q31_50Hz_200Hz, TEST_LENGTH_SAMPLES);
    riscv_float_to_q31(firCoeffs32LP, firCoeffs32LP_q31, NUM_TAPS);

    /* clang-format off */
    riscv_fir_interpolate_instance_q31 S;
    /* clang-format on */
    riscv_fir_interpolate_init_q31(&S, L, NUM_TAPS, firCoeffs32LP_q31, firStateq31,
                                 TEST_LENGTH_SAMPLES);
    BENCH_START(riscv_fir_interpolate_q31);
    riscv_fir_interpolate_q31(&S, testInput_q31_50Hz_200Hz,
                                interpolate_q31_output, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_fir_interpolate_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, interpolate_q31_output, (uint32_t)sizeof(interpolate_q31_output));
    printf("@@RESULT@@ case=firInterpolate_riscv_fir_interpolate_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
