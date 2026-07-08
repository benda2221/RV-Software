#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/StatisticsFunctions/absmin_f32/test_data.h"

BENCH_DECLARE_VAR();

static uint32_t f32_bits(float32_t value)
{
    union {
        float32_t f;
        uint32_t u;
    } bits;

    bits.f = value;
    return bits.u;
}

void absmin_riscv_absmin_f32(void)
{
    float32_t f32_output;
    uint32_t index;

    generate_rand_f32(absmin_f32_input, ARRAY_SIZE);

    BENCH_START(riscv_absmin_f32);
    riscv_absmin_f32(absmin_f32_input, ARRAY_SIZE, &f32_output, &index);
    BENCH_END(riscv_absmin_f32);

    printf("@@RESULT@@ case=riscv_absmin_f32 count=%u index=%u value_bits=0x%08x\n",
           (unsigned int)ARRAY_SIZE,
           (unsigned int)index,
           (unsigned int)f32_bits(f32_output));

    return;
}