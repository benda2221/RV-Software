#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/InterpolationFunctions/bilinear_interp_q7/test_data.h"

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


void bilinear_riscv_bilinear_interp_q7(void)
{
    generate_rand_q7(q7_z_array, NUM_ROWS * NUM_COLS);

    riscv_bilinear_interp_instance_q7 S_q7 = {
        NUM_ROWS,                   /*number of Rows*/
        NUM_COLS,                   /*number of Columns*/
        q7_z_array,           /*value of y*/
    };

    q7_t bilinear_interp_q7_output;

    BENCH_START(riscv_bilinear_interp_q7);
    bilinear_interp_q7_output = riscv_bilinear_interp_q7(&S_q7, x_q31_input, y_q31_input);
    BENCH_END(riscv_bilinear_interp_q7);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &bilinear_interp_q7_output, (uint32_t)sizeof(bilinear_interp_q7_output));
    printf("@@RESULT@@ case=bilinear_riscv_bilinear_interp_q7 hash=0x%08x\n", (unsigned int)__zr_hash);
}
