#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/MatrixFunctions/mat_vec_mult_q7/test_data.h"

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


void matVecMult_riscv_mat_vec_mult_q7(void)
{
    q7_t q7_output[M];
    riscv_matrix_instance_q7 q7_A;

    riscv_mat_init_q7(&q7_A, M, N, mat_q7_array);

    generate_rand_q7(mat_q7_array, M * N);
    generate_rand_q7(mat_q7_vec, N);

    BENCH_START(riscv_mat_vec_mult_q7);
    riscv_mat_vec_mult_q7(&q7_A, mat_q7_vec, q7_output);
    BENCH_END(riscv_mat_vec_mult_q7);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, q7_output, (uint32_t)sizeof(q7_output));
    printf("@@RESULT@@ case=matVecMult_riscv_mat_vec_mult_q7 hash=0x%08x\n", (unsigned int)__zr_hash);
}