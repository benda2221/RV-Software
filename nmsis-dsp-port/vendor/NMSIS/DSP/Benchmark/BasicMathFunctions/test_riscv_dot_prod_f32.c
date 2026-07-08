#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/dot_prod_f32/test_data.h"

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

void dot_prod_riscv_dot_prod_f32(void)
{
    float32_t dot_prod_f32_output;

    generate_rand_f32(dot_prod_f32_input1, ARRAY_SIZE_F32);
    generate_rand_f32(dot_prod_f32_input2, ARRAY_SIZE_F32);

    // f32_dot
    BENCH_START(riscv_dot_prod_f32);
    riscv_dot_prod_f32(dot_prod_f32_input1, dot_prod_f32_input2, ARRAY_SIZE_F32, &dot_prod_f32_output);
    BENCH_END(riscv_dot_prod_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, dot_prod_f32_input1, (uint32_t)sizeof(dot_prod_f32_input1));
    __zr_hash = zircon_result_hash_combine(__zr_hash, dot_prod_f32_input2, (uint32_t)sizeof(dot_prod_f32_input2));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &dot_prod_f32_output, (uint32_t)sizeof(dot_prod_f32_output));
    printf("@@RESULT@@ case=dot_prod_riscv_dot_prod_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}