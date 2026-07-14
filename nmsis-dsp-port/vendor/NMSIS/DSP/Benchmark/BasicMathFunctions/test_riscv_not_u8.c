#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/not_u8/test_data.h"

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


void not_riscv_not_u8(void)
{
    uint8_t not_u8_output[ARRAY_SIZE_U8];
    q7_t not_in[ARRAY_SIZE_U8];

    generate_rand_q7(not_in, ARRAY_SIZE_U8);

    BENCH_START(riscv_not_u8);
    riscv_not_u8((uint8_t *)not_in, not_u8_output, ARRAY_SIZE_U8);
    BENCH_END(riscv_not_u8);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, not_u8_output, (uint32_t)sizeof(not_u8_output));
    printf("@@RESULT@@ case=not_riscv_not_u8 hash=0x%08x\n", (unsigned int)__zr_hash);
}
