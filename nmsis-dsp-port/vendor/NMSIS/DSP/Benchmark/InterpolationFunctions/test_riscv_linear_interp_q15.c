#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/InterpolationFunctions/linear_interp_q15/test_data.h"

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


void linear_riscv_linear_interp_q15(void)
{

    generate_rand_q15(q15_y_array, ARRAY_SIZE);

    q15_t linear_interp_q15_output;

    BENCH_START(riscv_linear_interp_q15);
    linear_interp_q15_output = riscv_linear_interp_q15(q15_y_array, x_q15_input, ARRAY_SIZE);
    BENCH_END(riscv_linear_interp_q15);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &linear_interp_q15_output, (uint32_t)sizeof(linear_interp_q15_output));
    printf("@@RESULT@@ case=linear_riscv_linear_interp_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
}
