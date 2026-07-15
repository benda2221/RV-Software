#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/StatisticsFunctions/rms_q15/test_data.h"

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


void rms_riscv_rms_q15(void)
{
    q15_t q15_output;

    generate_rand_q15(rms_q15_input, ARRAY_SIZE);

    BENCH_START(riscv_rms_q15);
    riscv_rms_q15(rms_q15_input, ARRAY_SIZE, &q15_output);
    BENCH_END(riscv_rms_q15);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &q15_output, (uint32_t)sizeof(q15_output));
    printf("@@RESULT@@ case=rms_riscv_rms_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
}