#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/BasicMathFunctions/sub_q15/test_data.h"

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


void sub_riscv_sub_q15(void)
{
    q15_t sub_q15_output[ARRAY_SIZE_Q15];

    generate_rand_q15(sub_q15_input1, ARRAY_SIZE_Q15);
    generate_rand_q15(sub_q15_input2, ARRAY_SIZE_Q15);

    BENCH_START(riscv_sub_q15);
    riscv_sub_q15(sub_q15_input1, sub_q15_input2, sub_q15_output, ARRAY_SIZE_Q15);
    BENCH_END(riscv_sub_q15);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, sub_q15_output, (uint32_t)sizeof(sub_q15_output));
    printf("@@RESULT@@ case=sub_riscv_sub_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
}
