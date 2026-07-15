#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "riscv_common_tables.h"
#include "riscv_const_structs.h"
#include "TestData/TransformFunctions/cfft_radix4_q15/test_data.h"

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


void cfft_riscv_cfft_radix4_q15(void)
{
    generate_rand_q15(cfft_testinput_q15_50hz_200Hz, CFFTx4SIZE * 2);

    riscv_cfft_radix4_instance_q15 q15_S;
    riscv_status result = riscv_cfft_radix4_init_q15(&q15_S, CFFTx4SIZE, ifftFlag, doBitReverse);

    BENCH_START(riscv_cfft_radix4_q15);
    riscv_cfft_radix4_q15(&q15_S, cfft_testinput_q15_50hz_200Hz);
    BENCH_END(riscv_cfft_radix4_q15);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=cfft_riscv_cfft_radix4_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);
}