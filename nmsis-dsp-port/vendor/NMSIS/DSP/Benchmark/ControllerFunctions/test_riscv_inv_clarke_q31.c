#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ControllerFunctions/inv_clarke_q31/test_data.h"

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


void inv_clarke_riscv_inv_clarke_q31(void)
{
    q31_t Ia_q31[ARRAY_SIZE_Q31];
    q31_t Ib_q31[ARRAY_SIZE_Q31];

    generate_rand_q31(pIalpha_q31, ARRAY_SIZE_Q31);
    generate_rand_q31(pIbeta_q31, ARRAY_SIZE_Q31);

    volatile int i = 0;

    BENCH_START(riscv_inv_clarke_q31);
    for (i = 0; i < ARRAY_SIZE_Q31; i++) {
        riscv_inv_clarke_q31(pIalpha_q31[i], pIbeta_q31[i], &Ia_q31[i], &Ib_q31[i]);
    }
    BENCH_END(riscv_inv_clarke_q31);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, Ia_q31, (uint32_t)sizeof(Ia_q31));
    __zr_hash = zircon_result_hash_combine(__zr_hash, Ib_q31, (uint32_t)sizeof(Ib_q31));
    printf("@@RESULT@@ case=inv_clarke_riscv_inv_clarke_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
