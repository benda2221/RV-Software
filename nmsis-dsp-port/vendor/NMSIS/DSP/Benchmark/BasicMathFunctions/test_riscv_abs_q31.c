#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/abs_q31/test_data.h"

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


void abs_riscv_abs_q31(void)
{
    
    q31_t abs_q31_output[ARRAY_SIZE_Q31];
    
    generate_rand_q31(abs_q31_input, ARRAY_SIZE_Q31);

    // riscv_abs_q31.c
    BENCH_START(riscv_abs_q31);
    riscv_abs_q31(abs_q31_input, abs_q31_output, ARRAY_SIZE_Q31);
    BENCH_END(riscv_abs_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, abs_q31_output, (uint32_t)sizeof(abs_q31_output));
    printf("@@RESULT@@ case=abs_riscv_abs_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
