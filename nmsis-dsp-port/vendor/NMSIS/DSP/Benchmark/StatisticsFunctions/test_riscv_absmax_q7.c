#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/StatisticsFunctions/absmax_q7/test_data.h"

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


void absmax_riscv_absmax_q7(void)
{
    q7_t q7_output;
    uint32_t index;

    generate_rand_q7(absmax_q7_input, ARRAY_SIZE);

    BENCH_START(riscv_absmax_q7);
    riscv_absmax_q7(absmax_q7_input, ARRAY_SIZE, &q7_output, &index);
    BENCH_END(riscv_absmax_q7);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &q7_output, (uint32_t)sizeof(q7_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &index, (uint32_t)sizeof(index));
    printf("@@RESULT@@ case=absmax_riscv_absmax_q7 hash=0x%08x\n", (unsigned int)__zr_hash);
}