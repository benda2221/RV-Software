#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ComplexMathFunctions/cmplx_mult_real_q31/test_data.h"

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


void cmplx_mult_real_riscv_cmplx_mult_real_q31(void)
{

    q31_t cmplx_mult_real_q31_output[2 * ARRAY_SIZE_Q31];

    generate_rand_q31(cmplx_mult_real_q31_input1, 2 * ARRAY_SIZE_Q31);
    generate_rand_q31(cmplx_mult_real_q31_input2, 2 * ARRAY_SIZE_Q31);

    BENCH_START(riscv_cmplx_mult_real_q31);
    riscv_cmplx_mult_real_q31(cmplx_mult_real_q31_input1, cmplx_mult_real_q31_input2, cmplx_mult_real_q31_output, ARRAY_SIZE_Q31);
    BENCH_END(riscv_cmplx_mult_real_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, cmplx_mult_real_q31_output, (uint32_t)sizeof(cmplx_mult_real_q31_output));
    printf("@@RESULT@@ case=cmplx_mult_real_riscv_cmplx_mult_real_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
