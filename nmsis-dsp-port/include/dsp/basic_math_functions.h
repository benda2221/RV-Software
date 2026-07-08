#ifndef NMSIS_PORT_BASIC_MATH_FUNCTIONS_H
#define NMSIS_PORT_BASIC_MATH_FUNCTIONS_H

#include "dsp/port_types.h"

#define DECLARE_UNARY(name, type) \
    void name(const type *pSrc, type *pDst, uint32_t blockSize)
#define DECLARE_BINARY(name, type) \
    void name(const type *pSrcA, const type *pSrcB, type *pDst, uint32_t blockSize)

DECLARE_UNARY(riscv_abs_q7, q7_t);
DECLARE_UNARY(riscv_abs_q15, q15_t);
DECLARE_UNARY(riscv_abs_q31, q31_t);
DECLARE_UNARY(riscv_negate_q7, q7_t);
DECLARE_UNARY(riscv_negate_q15, q15_t);
DECLARE_UNARY(riscv_negate_q31, q31_t);
DECLARE_BINARY(riscv_add_q7, q7_t);
DECLARE_BINARY(riscv_add_q15, q15_t);
DECLARE_BINARY(riscv_add_q31, q31_t);
DECLARE_BINARY(riscv_sub_q7, q7_t);
DECLARE_BINARY(riscv_sub_q15, q15_t);
DECLARE_BINARY(riscv_sub_q31, q31_t);

#undef DECLARE_UNARY
#undef DECLARE_BINARY
#endif
