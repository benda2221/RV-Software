#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "riscv_common_tables.h"
#include "riscv_const_structs.h"
#include "TestData/TransformFunctions/cfft_q31/test_data.h"

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


#if !defined(RISCV_MATH_VECTOR)
void cfft_riscv_cfft_q31(void)
{
    generate_rand_q31(cfft_testinput_q31_50hz_200Hz, CFFTSIZE * 2);

    BENCH_START(riscv_cfft_q31);
    riscv_cfft_q31(&riscv_cfft_sR_q31_len512, cfft_testinput_q31_50hz_200Hz,
                 ifftFlag, doBitReverse);
    BENCH_END(riscv_cfft_q31);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &__zr_hash, (uint32_t)sizeof(__zr_hash));
    printf("@@RESULT@@ case=cfft_riscv_cfft_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}
#endif