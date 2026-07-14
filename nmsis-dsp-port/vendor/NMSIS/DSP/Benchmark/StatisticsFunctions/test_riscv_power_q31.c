#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/StatisticsFunctions/power_q31/test_data.h"

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


void power_riscv_power_q31(void)
{
    q63_t q63_output;

    generate_rand_q31(power_q31_input, ARRAY_SIZE);

    BENCH_START(riscv_power_q31);
    riscv_power_q31(power_q31_input, ARRAY_SIZE, &q63_output);
    BENCH_END(riscv_power_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &q63_output, (uint32_t)sizeof(q63_output));
    printf("@@RESULT@@ case=power_riscv_power_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}
