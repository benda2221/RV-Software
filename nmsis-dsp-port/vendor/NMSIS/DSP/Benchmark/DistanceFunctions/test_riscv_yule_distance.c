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


void yule_distance_riscv_yule_distance(void)
{
    float32_t yule_distance_f32_output;

    BENCH_START(riscv_yule_distance);
    yule_distance_f32_output = riscv_yule_distance(u32_yule_a_array, u32_yule_b_array, 36);
    BENCH_END(riscv_yule_distance);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &yule_distance_f32_output, (uint32_t)sizeof(yule_distance_f32_output));
    printf("@@RESULT@@ case=yule_distance_riscv_yule_distance hash=0x%08x\n", (unsigned int)__zr_hash);
return;
}