#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/sub_f32/test_data.h"

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

void sub_riscv_sub_f32(void)
{
    float32_t sub_f32_output[ARRAY_SIZE_F32];

    generate_rand_f32(sub_f32_input1, ARRAY_SIZE_F32);
    generate_rand_f32(sub_f32_input2, ARRAY_SIZE_F32);

    
    zircon_result_zero_f32(sub_f32_output, (uint32_t)(sizeof(sub_f32_output) / sizeof(sub_f32_output[0])));
BENCH_START(riscv_sub_f32);
    riscv_sub_f32(sub_f32_input1, sub_f32_input2, sub_f32_output, ARRAY_SIZE_F32);
    BENCH_END(riscv_sub_f32);



    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, sub_f32_output, (uint32_t)sizeof(sub_f32_output));
    printf("@@RESULT@@ case=sub_riscv_sub_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}