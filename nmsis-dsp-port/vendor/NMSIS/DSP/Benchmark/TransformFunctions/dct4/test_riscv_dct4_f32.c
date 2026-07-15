#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "riscv_common_tables.h"
#include "riscv_const_structs.h"
#include "TestData/TransformFunctions/dct4_f32/test_data.h"

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
void dct4_riscv_dct4_f32(void)
{
    riscv_cfft_radix4_instance_f32 S;
    riscv_rfft_instance_f32 SS;
    riscv_dct4_instance_f32 SSS;

    generate_rand_f32(dct4_testinput_f32_50hz_200Hz, DCT4SIZE);

    riscv_status result = riscv_dct4_init_f32(&SSS, &SS, &S, DCT4SIZE, DCT4SIZE / 2, NORMALIZE);
    BENCH_START(riscv_dct4_f32);
    riscv_dct4_f32(&SSS, f32_state, dct4_testinput_f32_50hz_200Hz);
    BENCH_END(riscv_dct4_f32);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=dct4_riscv_dct4_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
//    TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);

}
#endif
