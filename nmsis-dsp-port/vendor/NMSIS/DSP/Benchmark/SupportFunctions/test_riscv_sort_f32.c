#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/SupportFunctions/sort_f32/test_data.h"

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


void sort_riscv_sort_f32(void)
{
    float32_t f32_output[ARRAY_SIZE];

    generate_rand_f32(sort_f32_input, ARRAY_SIZE);

    riscv_sort_instance_f32 S_sort;
    riscv_sort_init_f32(&S_sort, RISCV_SORT_BUBBLE, RISCV_SORT_ASCENDING);

    
    zircon_result_zero_f32(f32_output, (uint32_t)(sizeof(f32_output) / sizeof(f32_output[0])));
BENCH_START(riscv_sort_f32);
    riscv_sort_f32(&S_sort, sort_f32_input, f32_output, ARRAY_SIZE);
    BENCH_END(riscv_sort_f32);


    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, f32_output, (uint32_t)sizeof(f32_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, sort_f32_input, (uint32_t)sizeof(sort_f32_input));
    printf("@@RESULT@@ case=sort_riscv_sort_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}