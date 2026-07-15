#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/and_u8/test_data.h"

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


void and_riscv_and_u8(void)
{
    uint8_t and_u8_output[ARRAY_SIZE_U8];
    q7_t and_in1[ARRAY_SIZE_U8];
    q7_t and_in2[ARRAY_SIZE_U8];

    generate_rand_q7(and_in1, ARRAY_SIZE_U8);
    generate_rand_q7(and_in2, ARRAY_SIZE_U8);

    BENCH_START(riscv_and_u8);
    riscv_and_u8((uint8_t *)and_in1, (uint8_t *)and_in2, and_u8_output, ARRAY_SIZE_U8);
    BENCH_END(riscv_and_u8);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, and_u8_output, (uint32_t)sizeof(and_u8_output));
    printf("@@RESULT@@ case=and_riscv_and_u8 hash=0x%08x\n", (unsigned int)__zr_hash);
}
