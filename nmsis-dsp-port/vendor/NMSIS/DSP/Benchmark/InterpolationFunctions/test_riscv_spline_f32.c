#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/InterpolationFunctions/spline_f32/test_data.h"

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

void spline_riscv_spline_f32(void)
{
    float32_t spline_f32_output[ARRAY_SIZE];

    riscv_spline_instance_f32 S_spline;

    riscv_spline_init_f32(&S_spline, RISCV_SPLINE_NATURAL, f32_x_array, f32_y_array, FUNC_SIZE, f32_spline_coef_array, f32_spline_temp_array);
    
    zircon_result_zero_f32(spline_f32_output, (uint32_t)(sizeof(spline_f32_output) / sizeof(spline_f32_output[0])));
BENCH_START(riscv_spline_f32);
    riscv_spline_f32(&S_spline, f32_test_x_array, spline_f32_output, SPLINE_FUNC_SIZE);
    BENCH_END(riscv_spline_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, spline_f32_output, (uint32_t)sizeof(spline_f32_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_spline_coef_array, (uint32_t)sizeof(f32_spline_coef_array));
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_spline_temp_array, (uint32_t)sizeof(f32_spline_temp_array));
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_x_array, (uint32_t)sizeof(f32_x_array));
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_y_array, (uint32_t)sizeof(f32_y_array));
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_test_x_array, (uint32_t)sizeof(f32_test_x_array));
    printf("@@RESULT@@ case=spline_riscv_spline_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}


