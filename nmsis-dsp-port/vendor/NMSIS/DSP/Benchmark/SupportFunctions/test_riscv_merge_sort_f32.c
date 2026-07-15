#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/SupportFunctions/merge_sort_f32/test_data.h"

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


void mergeSort_riscv_merge_sort_f32(void)
{
    
    float32_t f32_temp_array[ARRAY_SIZE];
    float32_t f32_out_array[ARRAY_SIZE];
    riscv_merge_sort_instance_f32 S_merge_sort;

    generate_rand_f32(merge_sort_f32_input, ARRAY_SIZE);
    riscv_merge_sort_init_f32(&S_merge_sort, RISCV_SORT_ASCENDING, f32_temp_array);

    
    zircon_result_zero_f32(f32_temp_array, (uint32_t)(sizeof(f32_temp_array) / sizeof(f32_temp_array[0])));
    zircon_result_zero_f32(f32_out_array, (uint32_t)(sizeof(f32_out_array) / sizeof(f32_out_array[0])));
BENCH_START(riscv_merge_sort_f32);
    riscv_merge_sort_f32(&S_merge_sort, merge_sort_f32_input, f32_out_array, ARRAY_SIZE);
    BENCH_END(riscv_merge_sort_f32);



    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, &__zr_hash, (uint32_t)sizeof(__zr_hash));
    printf("@@RESULT@@ case=mergeSort_riscv_merge_sort_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}
