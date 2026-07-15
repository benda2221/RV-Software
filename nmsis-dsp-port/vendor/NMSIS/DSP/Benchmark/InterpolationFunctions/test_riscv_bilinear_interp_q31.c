#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/InterpolationFunctions/bilinear_interp_q31/test_data.h"

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


void bilinear_riscv_bilinear_interp_q31(void)
{
    generate_rand_q31(q31_z_array, NUM_ROWS * NUM_COLS);

    riscv_bilinear_interp_instance_q31 S_q31 = {
        NUM_ROWS,                   /*number of Rows*/
        NUM_COLS,                   /*number of Columns*/
        q31_z_array,           /*value of y*/
    };

    q31_t bilinear_interp_q31_output;

    BENCH_START(riscv_bilinear_interp_q31);
    bilinear_interp_q31_output = riscv_bilinear_interp_q31(&S_q31, x_q31_input, y_q31_input);
    BENCH_END(riscv_bilinear_interp_q31);




    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &bilinear_interp_q31_output, (uint32_t)sizeof(bilinear_interp_q31_output));
    printf("@@RESULT@@ case=bilinear_riscv_bilinear_interp_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}
