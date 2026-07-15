#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/InterpolationFunctions/bilinear_interp_f32/test_data.h"

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

void bilinear_riscv_bilinear_interp_f32(void)
{
    generate_rand_f32(f32_z_array, NUM_ROWS * NUM_COLS);

    riscv_bilinear_interp_instance_f32 S_f32 = {
        NUM_ROWS,                 /*number of Rows*/
        NUM_COLS,                 /*number of Columns*/
        f32_z_array,        /*value of y*/
    };

    float32_t bilinear_interp_f32_output;

    BENCH_START(riscv_bilinear_interp_f32);
    bilinear_interp_f32_output = riscv_bilinear_interp_f32(&S_f32, x_f32_input, y_f32_input);
    BENCH_END(riscv_bilinear_interp_f32);



    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &bilinear_interp_f32_output, (uint32_t)sizeof(bilinear_interp_f32_output));
    printf("@@RESULT@@ case=bilinear_riscv_bilinear_interp_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}