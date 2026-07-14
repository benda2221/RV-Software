#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ControllerFunctions/inv_park_q31/test_data.h"

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


void inv_park_riscv_inv_park_q31(void)
{
    q31_t pIalpha_q31[ARRAY_SIZE_Q31];
    q31_t pIbeta_q31[ARRAY_SIZE_Q31];

    volatile int i = 0;

    generate_rand_q31(Ia_q31, ARRAY_SIZE_Q31);
    generate_rand_q31(Ib_q31, ARRAY_SIZE_Q31);
    riscv_float_to_q31(sinVal_f32, sinVal_q31, ARRAY_SIZE_Q31);
    riscv_float_to_q31(cosVal_f32, cosVal_q31, ARRAY_SIZE_Q31);

    BENCH_START(riscv_inv_park_q31);
    for (i = 0; i < ARRAY_SIZE_Q31; i++) {
        riscv_inv_park_q31(Ia_q31[i], Ib_q31[i], &pIalpha_q31[i], &pIbeta_q31[i], sinVal_q31[i], cosVal_q31[i]);
    }
    BENCH_END(riscv_inv_park_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, pIalpha_q31, (uint32_t)sizeof(pIalpha_q31));
    __zr_hash = zircon_result_hash_combine(__zr_hash, pIbeta_q31, (uint32_t)sizeof(pIbeta_q31));
    printf("@@RESULT@@ case=inv_park_riscv_inv_park_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}