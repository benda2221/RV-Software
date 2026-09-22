#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/fir_lattice_q15/test_data.h"

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


void firLattice_riscv_fir_lattice_q15(void)
{
    q15_t firStateq15[TEST_LENGTH_SAMPLES + NUM_TAPS - 1];
    q15_t lattice_q15_output[TEST_LENGTH_SAMPLES];

    generate_rand_q15(testInput_q15_50Hz_200Hz, TEST_LENGTH_SAMPLES);
    generate_rand_q15(firCoeffs32LP_q15, NUM_TAPS);
    /* clang-format off */
    riscv_fir_lattice_instance_q15 S;
    /* clang-format on */
    riscv_fir_lattice_init_q15(&S, NUM_TAPS, firCoeffs32LP_q15, firStateq15);
    BENCH_START(riscv_fir_lattice_q15);
    riscv_fir_lattice_q15(&S, testInput_q15_50Hz_200Hz, lattice_q15_output, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_fir_lattice_q15);

    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, lattice_q15_output, (uint32_t)sizeof(lattice_q15_output));
    printf("@@RESULT@@ case=firLattice_riscv_fir_lattice_q15 hash=0x%08x\n", (unsigned int)__zr_hash);
}
