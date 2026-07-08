#include "ref.h"

riscv_status ref_mat_mult_f32(const riscv_matrix_instance_f32 *pSrcA,
                              const riscv_matrix_instance_f32 *pSrcB,
                              riscv_matrix_instance_f32 *pDst)
{
    uint32_t outR = pSrcA->numRows;
    uint32_t outC = pSrcB->numCols;
    uint32_t innerSize = pSrcA->numCols;

    for (uint32_t r = 0; r < outR; r++) {
        for (uint32_t c = 0; c < outC; c++) {
            float32_t sum = 0.0f;
            for (uint32_t i = 0; i < innerSize; i++) {
                sum += pSrcA->pData[r * innerSize + i] * pSrcB->pData[i * outC + c];
            }
            pDst->pData[r * outC + c] = sum;
        }
    }

    return RISCV_MATH_SUCCESS;
}

riscv_status ref_mat_add_f32(const riscv_matrix_instance_f32 *pSrcA,
                             const riscv_matrix_instance_f32 *pSrcB,
                             riscv_matrix_instance_f32 *pDst)
{
    uint32_t numSamples = (uint32_t)pSrcA->numRows * pSrcA->numCols;

    for (uint32_t i = 0; i < numSamples; i++) {
        pDst->pData[i] = pSrcA->pData[i] + pSrcB->pData[i];
    }

    return RISCV_MATH_SUCCESS;
}

riscv_status ref_mat_trans_f32(const riscv_matrix_instance_f32 *pSrc,
                               riscv_matrix_instance_f32 *pDst)
{
    uint32_t numR = pSrc->numRows;
    uint32_t numC = pSrc->numCols;

    for (uint32_t r = 0; r < numR; r++) {
        for (uint32_t c = 0; c < numC; c++) {
            pDst->pData[c * numR + r] = pSrc->pData[r * numC + c];
        }
    }

    return RISCV_MATH_SUCCESS;
}
