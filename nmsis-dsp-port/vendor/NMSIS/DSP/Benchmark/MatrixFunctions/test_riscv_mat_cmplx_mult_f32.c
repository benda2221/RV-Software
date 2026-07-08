#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/MatrixFunctions/mat_cmplx_mult_f32/test_data.h"

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

void matCmplxMult_riscv_mat_cmplx_mult_f32(void)
{
    float32_t f32_output[2 * M * N];
    riscv_matrix_instance_f32 f32_A;
    riscv_matrix_instance_f32 f32_B;
    riscv_matrix_instance_f32 f32_des;
    riscv_mat_init_f32(&f32_A, M, K / 2, (float32_t *)mat_cmplx_mult_f32_arrayA);
    riscv_mat_init_f32(&f32_B, K / 2, N, (float32_t *)mat_cmplx_mult_f32_arrayB);
    riscv_mat_init_f32(&f32_des, M, N, f32_output);

    generate_rand_f32(mat_cmplx_mult_f32_arrayA, M * K);
    generate_rand_f32(mat_cmplx_mult_f32_arrayB, K * N);

    
    zircon_result_zero_f32(f32_output, (uint32_t)(sizeof(f32_output) / sizeof(f32_output[0])));
BENCH_START(riscv_mat_cmplx_mult_f32);
    riscv_status result = riscv_mat_cmplx_mult_f32(&f32_A, &f32_B, &f32_des);
    BENCH_END(riscv_mat_cmplx_mult_f32);

    
    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_output, (uint32_t)sizeof(f32_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, mat_cmplx_mult_f32_arrayA, (uint32_t)sizeof(mat_cmplx_mult_f32_arrayA));
    __zr_hash = zircon_result_hash_combine(__zr_hash, mat_cmplx_mult_f32_arrayB, (uint32_t)sizeof(mat_cmplx_mult_f32_arrayB));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=matCmplxMult_riscv_mat_cmplx_mult_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);
}
