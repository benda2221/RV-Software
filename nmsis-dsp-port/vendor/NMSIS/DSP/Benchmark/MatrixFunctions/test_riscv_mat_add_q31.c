#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/MatrixFunctions/mat_add_q31/test_data.h"

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


void matAdd_riscv_mat_add_q31(void)
{
    riscv_matrix_instance_q31 q31_A;
    riscv_matrix_instance_q31 q31_B;
    riscv_matrix_instance_q31 q31_des;
    q31_t mat_add_q31_output[M * N];

    riscv_mat_init_q31(&q31_A, M, N, (q31_t *)mat_add_q31_arrayA);
    riscv_mat_init_q31(&q31_B, M, N, (q31_t *)mat_add_q31_arrayB);
    riscv_mat_init_q31(&q31_des, M, N, mat_add_q31_output);

    generate_rand_q31(mat_add_q31_arrayA, M * N);
    generate_rand_q31(mat_add_q31_arrayB, M * N);

    BENCH_START(riscv_mat_add_q31);
    riscv_status result = riscv_mat_add_q31(&q31_A, &q31_B, &q31_des);
    BENCH_END(riscv_mat_add_q31);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, mat_add_q31_output, (uint32_t)sizeof(mat_add_q31_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, &result, (uint32_t)sizeof(result));
    printf("@@RESULT@@ case=matAdd_riscv_mat_add_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
TEST_ASSERT_EQUAL(RISCV_MATH_SUCCESS, result);
}