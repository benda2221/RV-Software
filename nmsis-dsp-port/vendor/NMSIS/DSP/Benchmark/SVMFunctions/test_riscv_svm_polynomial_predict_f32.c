#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/SVMFunctions/svm_polynomial_predict_f32/test_data.h"

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

void svm_riscv_svm_polynomial_predict_f32(void)
{
    int32_t result;
    riscv_svm_polynomial_instance_f32 params;

    for (int i = 0; i < NB_SUPPORT_VECTORS; i++) {
        dualCoefficients[i] = (float32_t)rand() / RAND_MAX * 2 - 1;
    }
    generate_rand_f32(f32_input, VECTOR_DIMENSION);
    generate_rand_f32(supportVectors, NB_SUPPORT_VECTORS * VECTOR_DIMENSION);

    riscv_svm_polynomial_init_f32(&params,
        NB_SUPPORT_VECTORS,
        VECTOR_DIMENSION,
        intercept,
        dualCoefficients,
        supportVectors,
        classes,
        degree,
        coef0_f32,
        gamma_f32
    );


    BENCH_START(riscv_svm_polynomial_predict_f32);
    riscv_svm_polynomial_predict_f32(&params, f32_input, &result);
    BENCH_END(riscv_svm_polynomial_predict_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=svm_riscv_svm_polynomial_predict_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}
