#include "riscv_math.h"
#include <stdio.h>
#include "validate.h"
#include "nmsis_bench.h"
#include "TestData/FilteringFunctions/iir_lattice_q31/test_data.h"

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


void iirLattice_riscv_iir_lattice_q31(void)
{
    q31_t iir_lattice_q31_output[TEST_LENGTH_SAMPLES];
    q31_t IIRStateQ31[TEST_LENGTH_SAMPLES + numStages];

    /* clang-format off */
    riscv_iir_lattice_instance_q31 S;
    generate_rand_q31(testInput_q31_50Hz_200Hz, TEST_LENGTH_SAMPLES);

    /* clang-format on */
    riscv_iir_lattice_init_q31(&S, numStages, IIRCoeffs32LP_K_q31, IIRCoeffs32LP_V_q31, IIRStateQ31, TEST_LENGTH_SAMPLES);
    BENCH_START(riscv_iir_lattice_q31);
    riscv_iir_lattice_q31(&S, testInput_q31_50Hz_200Hz, iir_lattice_q31_output, TEST_LENGTH_SAMPLES);
    BENCH_END(riscv_iir_lattice_q31);





    uint32_t __zr_hash = 2166136261u;
    __zr_hash = zircon_result_hash_combine(__zr_hash, iir_lattice_q31_output, (uint32_t)sizeof(iir_lattice_q31_output));
    printf("@@RESULT@@ case=iirLattice_riscv_iir_lattice_q31 hash=0x%08x\n", (unsigned int)__zr_hash);
}
