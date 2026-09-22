#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/StatisticsFunctions/min_q15/test_data.h"

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


void min_riscv_min_q15(void)
{
    q15_t q15_output;
    uint32_t index;

    generate_rand_q15(min_q15_input, ARRAY_SIZE);

    BENCH_START(riscv_min_q15);
    riscv_min_q15(min_q15_input, ARRAY_SIZE, &q15_output, &index);
    BENCH_END(riscv_min_q15);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &q15_output, (uint32_t)sizeof(q15_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &index, (uint32_t)sizeof(index));
    printf("@@RESULT@@ case=min_riscv_min_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
}