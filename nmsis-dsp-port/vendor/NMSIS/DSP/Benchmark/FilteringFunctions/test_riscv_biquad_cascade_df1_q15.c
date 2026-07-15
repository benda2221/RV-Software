#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/biquad_cascade_df1_q15/test_data.h"

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


void df1_riscv_biquad_cascade_df1_q15(void)
{
    q15_t biquad_cascade_df1_q15_output[TEST_LENGTH_SAMPLES];
    q15_t IIRStateq15[4 * numStages];

    riscv_biquad_casd_df1_inst_q15 S;
    generate_rand_q15(testInput_q15_50Hz_200Hz, TEST_LENGTH_SAMPLES);

    riscv_biquad_cascade_df1_init_q15(&S, numStages, IIRCoeffsQ15LP, IIRStateq15, 1);
    BENCH_START(riscv_biquad_cascade_df1_q15);
    riscv_biquad_cascade_df1_q15(&S, testInput_q15_50Hz_200Hz, biquad_cascade_df1_q15_output, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_biquad_cascade_df1_q15);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, biquad_cascade_df1_q15_output, (uint32_t)sizeof(biquad_cascade_df1_q15_output));
    printf("@@RESULT@@ case=df1_riscv_biquad_cascade_df1_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
