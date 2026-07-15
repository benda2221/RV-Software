#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "riscv_common_tables.h"
#include "riscv_const_structs.h"
#include "TestData/TransformFunctions/rfft_fast_f32/test_data.h"

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

static void zircon_result_zero_f32(float32_t *data, uint32_t length)
{
    for (uint32_t i = 0; i < length; i++) {
        data[i] = 0.0f;
    }
}


#if !defined(RISCV_MATH_VECTOR)
void rfft_riscv_rfft_fast_f32(void)
{
    float32_t rfft_fast_f32_output[2 * RFFTSIZE];

    generate_rand_f32(rfft_testinput_f32_50hz_200Hz_fast, RFFTSIZE);
    riscv_rfft_fast_instance_f32 SS;

    riscv_status result = riscv_rfft_fast_init_f32(&SS, RFFTSIZE);
    
    zircon_result_zero_f32(rfft_fast_f32_output, (uint32_t)(sizeof(rfft_fast_f32_output) / sizeof(rfft_fast_f32_output[0])));
BENCH_START(riscv_rfft_fast_f32);
    riscv_rfft_fast_f32(&SS, rfft_testinput_f32_50hz_200Hz_fast, rfft_fast_f32_output, ifftFlag);
    BENCH_END(riscv_rfft_fast_f32);

    


    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, rfft_fast_f32_output, (uint32_t)sizeof(rfft_fast_f32_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=rfft_riscv_rfft_fast_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);
}
#endif