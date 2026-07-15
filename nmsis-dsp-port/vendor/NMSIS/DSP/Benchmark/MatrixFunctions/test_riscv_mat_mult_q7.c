#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/MatrixFunctions/mat_mult_q7/test_data.h"

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


void matMult_riscv_mat_mult_q7(void)
{
    q7_t q7_output[M * N];
    q7_t q7_output_back[K * N];
    riscv_matrix_instance_q7 q7_A;
    riscv_matrix_instance_q7 q7_B;
    riscv_matrix_instance_q7 q7_des;

    riscv_mat_init_q7(&q7_A, M, K, (q7_t *)mat_mult_q7_arrayA);
    riscv_mat_init_q7(&q7_B, K, N, (q7_t *)mat_mult_q7_arrayB);
    riscv_mat_init_q7(&q7_des, M, N, q7_output);

    generate_rand_q7(mat_mult_q7_arrayA, M * K);
    generate_rand_q7(mat_mult_q7_arrayB, K * N);

    BENCH_START(riscv_mat_mult_q7);
    riscv_status result = riscv_mat_mult_q7(&q7_A, &q7_B, &q7_des, q7_output_back);
    BENCH_END(riscv_mat_mult_q7);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, q7_output, (uint32_t)sizeof(q7_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, q7_output_back, (uint32_t)sizeof(q7_output_back));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=matMult_riscv_mat_mult_q7 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);
}
