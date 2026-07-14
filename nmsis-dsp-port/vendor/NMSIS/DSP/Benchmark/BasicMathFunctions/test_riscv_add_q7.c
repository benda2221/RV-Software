#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/add_q7/test_data.h"

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


void add_riscv_add_q7(void)
{
    q7_t add_q7_output[ARRAY_SIZE_Q7];

    generate_rand_q7(add_q7_input1, ARRAY_SIZE_Q7);
    generate_rand_q7(add_q7_input2, ARRAY_SIZE_Q7);
    // riscv_add_q7.c
    BENCH_START(riscv_add_q7);
    riscv_add_q7(add_q7_input1, add_q7_input2, add_q7_output, ARRAY_SIZE_Q7);
    BENCH_END(riscv_add_q7);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, add_q7_output, (uint32_t)sizeof(add_q7_output));
    printf("@@RESULT@@ case=add_riscv_add_q7 hash=0x%08x\n", (unsigned int)__zr_hash);
}
