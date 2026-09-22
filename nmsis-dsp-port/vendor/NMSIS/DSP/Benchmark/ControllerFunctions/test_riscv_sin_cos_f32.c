#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/ControllerFunctions/sin_cos_f32/test_data.h"

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


void sin_cos_riscv_sin_cos_f32(void)
{
    volatile int i;
    float32_t pSinVal_f32[ARRAY_SIZE_F32];
    float32_t pCosVal_f32[ARRAY_SIZE_F32];

    for (i = 0; i < ARRAY_SIZE_F32; i++) {
        sin_cos_f32_input[i] = (float32_t)rand() / 0x7ff;
    }

    
    zircon_result_zero_f32(pSinVal_f32, (uint32_t)(sizeof(pSinVal_f32) / sizeof(pSinVal_f32[0])));
    zircon_result_zero_f32(pCosVal_f32, (uint32_t)(sizeof(pCosVal_f32) / sizeof(pCosVal_f32[0])));
BENCH_START(riscv_sin_cos_f32);
    for (i = 0; i < ARRAY_SIZE_F32; i++) {
        riscv_sin_cos_f32(sin_cos_f32_input[i], &pSinVal_f32[i], &pCosVal_f32[i]);
    }
    BENCH_END(riscv_sin_cos_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, pSinVal_f32, (uint32_t)sizeof(pSinVal_f32));
    __zr_hash = zircon_result_hash_combine(__zr_hash, pCosVal_f32, (uint32_t)sizeof(pCosVal_f32));
    printf("@@RESULT@@ case=sin_cos_riscv_sin_cos_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}