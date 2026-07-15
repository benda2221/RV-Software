#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/MatrixFunctions/mat_vec_mult_f32/test_data.h"

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

void matVecMult_riscv_mat_vec_mult_f32(void)
{
    float32_t f32_output[M];
    riscv_matrix_instance_f32 f32_A;

    riscv_mat_init_f32(&f32_A, M, N, mat_f32_array);

    generate_rand_f32(mat_f32_array, M * N);
    generate_rand_f32(mat_f32_vec, N);

    
    zircon_result_zero_f32(f32_output, (uint32_t)(sizeof(f32_output) / sizeof(f32_output[0])));
BENCH_START(riscv_mat_vec_mult_f32);
    riscv_mat_vec_mult_f32(&f32_A, mat_f32_vec, f32_output);
    BENCH_END(riscv_mat_vec_mult_f32);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_output, (uint32_t)sizeof(f32_output));
    printf("@@RESULT@@ case=matVecMult_riscv_mat_vec_mult_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}