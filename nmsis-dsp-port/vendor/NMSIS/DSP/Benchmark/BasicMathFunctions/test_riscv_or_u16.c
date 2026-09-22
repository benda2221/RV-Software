#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/or_u16/test_data.h"

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


void or_riscv_or_u16(void)
{
    uint16_t or_u16_output[ARRAY_SIZE_U16];
    q15_t or_in1[ARRAY_SIZE_U16];
    q15_t or_in2[ARRAY_SIZE_U16];

    generate_rand_q15(or_in1, ARRAY_SIZE_U16);
    generate_rand_q15(or_in2, ARRAY_SIZE_U16);

    BENCH_START(riscv_or_u16);
    riscv_or_u16((uint16_t *)or_in1, (uint16_t *)or_in2, or_u16_output, ARRAY_SIZE_U16);
    BENCH_END(riscv_or_u16);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, or_u16_output, (uint32_t)sizeof(or_u16_output));
    printf("@@RESULT@@ case=or_riscv_or_u16 hash=0x%08x\n", (unsigned int)__zr_hash);
}
