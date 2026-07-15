#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/xor_u32/test_data.h"

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


void xor_riscv_xor_u32(void)
{
    uint32_t xor_u32_output[ARRAY_SIZE_U32];
    q31_t xor_in1[ARRAY_SIZE_U32];
    q31_t xor_in2[ARRAY_SIZE_U32];

    generate_rand_q31(xor_in1, ARRAY_SIZE_U32);
    generate_rand_q31(xor_in2, ARRAY_SIZE_U32);

    BENCH_START(riscv_xor_u32);
    riscv_xor_u32((uint32_t *)xor_in1, (uint32_t *)xor_in2, xor_u32_output, ARRAY_SIZE_U32);
    BENCH_END(riscv_xor_u32);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, xor_u32_output, (uint32_t)sizeof(xor_u32_output));
    printf("@@RESULT@@ case=xor_riscv_xor_u32 hash=0x%08x\n", (unsigned int)__zr_hash);
}
