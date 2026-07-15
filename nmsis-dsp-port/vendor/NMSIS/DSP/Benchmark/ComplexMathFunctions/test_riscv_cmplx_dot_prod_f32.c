#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ComplexMathFunctions/cmplx_dot_prod_f32/test_data.h"

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

void cmplx_dot_prod_riscv_cmplx_dot_prod_f32(void)
{

    float32_t cmplx_dot_prod_f32_realOutput, cmplx_dot_prod_f32_imagOutput;

    generate_rand_f32(cmplx_dot_prod_f32_input1, 2 * ARRAY_SIZE_F32);
    generate_rand_f32(cmplx_dot_prod_f32_input2, 2 * ARRAY_SIZE_F32);

    BENCH_START(riscv_cmplx_dot_prod_f32);
    riscv_cmplx_dot_prod_f32(cmplx_dot_prod_f32_input1, cmplx_dot_prod_f32_input2, ARRAY_SIZE_F32,
                           &cmplx_dot_prod_f32_realOutput,
                           &cmplx_dot_prod_f32_imagOutput);
    BENCH_END(riscv_cmplx_dot_prod_f32);

    



    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &cmplx_dot_prod_f32_realOutput, (uint32_t)sizeof(cmplx_dot_prod_f32_realOutput));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &cmplx_dot_prod_f32_imagOutput, (uint32_t)sizeof(cmplx_dot_prod_f32_imagOutput));
    printf("@@RESULT@@ case=cmplx_dot_prod_riscv_cmplx_dot_prod_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}
