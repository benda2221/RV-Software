#ifndef NMSIS_PORT_FILTERING_FUNCTIONS_H
#define NMSIS_PORT_FILTERING_FUNCTIONS_H

#include "dsp/port_types.h"

typedef struct {
    uint32_t numStages;
    q31_t *pState;
    const q31_t *pCoeffs;
    uint8_t postShift;
} riscv_biquad_casd_df1_inst_q31;

void riscv_biquad_cascade_df1_init_q31(
    riscv_biquad_casd_df1_inst_q31 *S, uint8_t numStages,
    const q31_t *pCoeffs, q31_t *pState, int8_t postShift);
void riscv_biquad_cascade_df1_q31(
    const riscv_biquad_casd_df1_inst_q31 *S, const q31_t *pSrc,
    q31_t *pDst, uint32_t blockSize);

#endif
