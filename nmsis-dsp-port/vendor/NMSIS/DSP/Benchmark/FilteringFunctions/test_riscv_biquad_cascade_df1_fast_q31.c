#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/biquad_cascade_df1_q31/test_data.h"

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


void df1_riscv_biquad_cascade_df1_fast_q31(void)
{
    q31_t biquad_cascade_df1_q31_output[TEST_LENGTH_SAMPLES];
    q31_t IIRStateq31[4 * numStages];

    riscv_biquad_casd_df1_inst_q31 S;
    generate_rand_q31(testInput_q31_50Hz_200Hz, TEST_LENGTH_SAMPLES);
    float32_t IIRCoeffs32LP[5 * numStages];

    for (int i = 0; i < 5 * numStages; i++) {
        IIRCoeffs32LP[i] = (float32_t)rand() / RAND_MAX * 2 - 1;
    }
    riscv_float_to_q31(IIRCoeffs32LP, IIRCoeffsQ31LP, 5 * numStages);

    riscv_biquad_cascade_df1_init_q31(&S, numStages, IIRCoeffsQ31LP, IIRStateq31, 0);
    BENCH_START(riscv_biquad_cascade_df1_fast_q31);
    riscv_biquad_cascade_df1_fast_q31(&S, testInput_q31_50Hz_200Hz, biquad_cascade_df1_q31_output, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_biquad_cascade_df1_fast_q31);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, biquad_cascade_df1_q31_output, (uint32_t)sizeof(biquad_cascade_df1_q31_output));
    printf("@@RESULT@@ case=df1_riscv_biquad_cascade_df1_fast_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
