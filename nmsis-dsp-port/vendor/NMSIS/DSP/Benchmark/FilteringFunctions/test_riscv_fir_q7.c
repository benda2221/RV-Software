#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/fir_q7/test_data.h"

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


void fir_riscv_fir_q7(void)
{
    q7_t firStateq7[TEST_LENGTH_SAMPLES_Q7 + NUM_TAPS_Q7 - 1];
    q7_t fir_q7_output[TEST_LENGTH_SAMPLES_Q7];

    generate_rand_q7(testInput_q7_50Hz_200Hz, TEST_LENGTH_SAMPLES_Q7);
    riscv_float_to_q7(firCoeffs32LP, firCoeffLP_q7, NUM_TAPS_Q7);

    /* clang-format off */
    riscv_fir_instance_q7 S;
    /* clang-format on */
    riscv_fir_init_q7(&S, NUM_TAPS_Q7, firCoeffLP_q7, firStateq7, TEST_LENGTH_SAMPLES_Q7);
    BENCH_START(riscv_fir_q7);
    riscv_fir_q7(&S, testInput_q7_50Hz_200Hz, fir_q7_output, TEST_LENGTH_SAMPLES_Q7);
    BENCH_END(riscv_fir_q7);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, fir_q7_output, (uint32_t)sizeof(fir_q7_output));
    printf("@@RESULT@@ case=fir_riscv_fir_q7 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
