#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/iir_lattice_f32/test_data.h"

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

void iirLattice_riscv_iir_lattice_f32(void)
{
    float32_t iir_lattice_f32_output[TEST_LENGTH_SAMPLES];
    float32_t IIRStateF32[TEST_LENGTH_SAMPLES + numStages];

    /* clang-format off */
    riscv_iir_lattice_instance_f32 S;
    generate_rand_f32(testInput_f32_50Hz_200Hz, TEST_LENGTH_SAMPLES);

    /* clang-format on */
    riscv_iir_lattice_init_f32(&S, numStages, IIRCoeffs32LP_K, IIRCoeffs32LP_V, IIRStateF32, TEST_LENGTH_SAMPLES);
    
    zircon_result_zero_f32(iir_lattice_f32_output, (uint32_t)(sizeof(iir_lattice_f32_output) / sizeof(iir_lattice_f32_output[0])));
    zircon_result_zero_f32(IIRStateF32, (uint32_t)(sizeof(IIRStateF32) / sizeof(IIRStateF32[0])));
BENCH_START(riscv_iir_lattice_f32);
    riscv_iir_lattice_f32(&S, testInput_f32_50Hz_200Hz, iir_lattice_f32_output, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_iir_lattice_f32);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, iir_lattice_f32_output, (uint32_t)sizeof(iir_lattice_f32_output));
    __zr_hash = zircon_result_hash_combine(__zr_hash, IIRStateF32, (uint32_t)sizeof(IIRStateF32));
    __zr_hash = zircon_result_hash_combine(__zr_hash, testInput_f32_50Hz_200Hz, (uint32_t)sizeof(testInput_f32_50Hz_200Hz));
    __zr_hash = zircon_result_hash_combine(__zr_hash, IIRCoeffs32LP_K, (uint32_t)sizeof(IIRCoeffs32LP_K));
    __zr_hash = zircon_result_hash_combine(__zr_hash, IIRCoeffs32LP_V, (uint32_t)sizeof(IIRCoeffs32LP_V));
    printf("@@RESULT@@ case=iirLattice_riscv_iir_lattice_f32 hash=0x%08x\n", (unsigned int)__zr_hash);
}