#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "array.h"

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


void sokalmichener_distance_riscv_sokalmichener_distance(void)
{
    float32_t sokalmichener_distance_f32_output;

    BENCH_START(riscv_sokalmichener_distance);
    sokalmichener_distance_f32_output = riscv_sokalmichener_distance(u32_sokalmichener_a_array, u32_sokalmichener_b_array, 36);
    BENCH_END(riscv_sokalmichener_distance);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &sokalmichener_distance_f32_output, (uint32_t)sizeof(sokalmichener_distance_f32_output));
    printf("@@RESULT@@ case=sokalmichener_distance_riscv_sokalmichener_distance hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}