#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "riscv_common_tables.h"
#include "riscv_const_structs.h"
#include "TestData/TransformFunctions/rfft_q31/test_data.h"

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
void rfft_riscv_rfft_q31(void)
{
    q31_t rfft_q31_output[2 * RFFTSIZE];
    riscv_rfft_instance_q31 SS;
    generate_rand_q31(rfft_testinput_q31_50hz_200Hz, RFFTSIZE);

    riscv_status result = riscv_rfft_init_q31(&SS, RFFTSIZE, ifftFlag, doBitReverse);
    BENCH_START(riscv_rfft_q31);
    riscv_rfft_q31(&SS, rfft_testinput_q31_50hz_200Hz, rfft_q31_output);
    BENCH_END(riscv_rfft_q31);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, rfft_q31_output, (uint32_t)sizeof(rfft_q31_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=rfft_riscv_rfft_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);
}
#endif
