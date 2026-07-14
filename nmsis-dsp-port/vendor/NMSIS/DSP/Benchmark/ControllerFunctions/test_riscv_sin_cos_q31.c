#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ControllerFunctions/sin_cos_q31/test_data.h"

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


void sin_cos_riscv_sin_cos_q31(void)
{
    volatile int i;
    q31_t pSinVal_q31[ARRAY_SIZE_Q31];
    q31_t pCosVal_q31[ARRAY_SIZE_Q31];

    for (i = 0; i < ARRAY_SIZE_Q31; i++) {
        sin_cos_q31_input[i] = (float32_t)rand() / 0x7ff;
    }

    BENCH_START(riscv_sin_cos_q31);
    for (i = 0; i < ARRAY_SIZE_Q31; i++) {
        riscv_sin_cos_q31(sin_cos_q31_input[i], &pSinVal_q31[i], &pCosVal_q31[i]);
    }
    BENCH_END(riscv_sin_cos_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, pSinVal_q31, (uint32_t)sizeof(pSinVal_q31));
    __zr_hash = zircon_result_hash_combine(__zr_hash, pCosVal_q31, (uint32_t)sizeof(pCosVal_q31));
    printf("@@RESULT@@ case=sin_cos_riscv_sin_cos_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}
