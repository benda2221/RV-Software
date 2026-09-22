#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/fir_lattice_f32/test_data.h"

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

static uint32_t zircon_result_f32_bits(float32_t value)
{
    union {
        float32_t f;
        uint32_t u;
    } bits;

    bits.f = value;
    return bits.u;
}

void firLattice_riscv_fir_lattice_f32(void)
{
    float32_t firStatef32[TEST_LENGTH_SAMPLES + NUM_TAPS - 1];
    float32_t lattice_f32_output[TEST_LENGTH_SAMPLES];

    generate_rand_f32(testInput_f32_50Hz_200Hz, TEST_LENGTH_SAMPLES);
    generate_rand_f32(firCoeffs32LP, NUM_TAPS);
    /* clang-format off */
    riscv_fir_lattice_instance_f32 S;
    /* clang-format on */
    riscv_fir_lattice_init_f32(&S, NUM_TAPS, firCoeffs32LP, firStatef32);
    
    zircon_result_zero_f32(firStatef32, (uint32_t)(sizeof(firStatef32) / sizeof(firStatef32[0])));
    zircon_result_zero_f32(lattice_f32_output, (uint32_t)(sizeof(lattice_f32_output) / sizeof(lattice_f32_output[0])));
#ifdef ZIRCON_FIR_LATTICE_TRACE
    for (uint32_t i = 0; i < 4; i++) {
        printf("@@FIRLATTICE_PRE@@ input index=%u bits=0x%08x\n",
               (unsigned int)i,
               (unsigned int)zircon_result_f32_bits(testInput_f32_50Hz_200Hz[i]));
        printf("@@FIRLATTICE_PRE@@ coeff index=%u bits=0x%08x\n",
               (unsigned int)i,
               (unsigned int)zircon_result_f32_bits(firCoeffs32LP[i]));
        printf("@@FIRLATTICE_PRE@@ state index=%u bits=0x%08x\n",
               (unsigned int)i,
               (unsigned int)zircon_result_f32_bits(firStatef32[i]));
    }
#endif
BENCH_START(riscv_fir_lattice_f32);
    riscv_fir_lattice_f32(&S, testInput_f32_50Hz_200Hz, lattice_f32_output, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_fir_lattice_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, lattice_f32_output, (uint32_t)sizeof(lattice_f32_output));
    printf("@@RESULT@@ case=firLattice_riscv_fir_lattice_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
#ifdef ZIRCON_FIR_LATTICE_TRACE
    for (uint32_t i = 0; i < TEST_LENGTH_SAMPLES; i++) {
        printf("@@FIRLATTICE_OUT@@ index=%u bits=0x%08x\n",
               (unsigned int)i,
               (unsigned int)zircon_result_f32_bits(lattice_f32_output[i]));
    }
#endif

}