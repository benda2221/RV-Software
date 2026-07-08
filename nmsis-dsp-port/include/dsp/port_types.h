#ifndef NMSIS_PORT_TYPES_H
#define NMSIS_PORT_TYPES_H

#include <stdint.h>
#include <tool.h>

#define RISCV_DSP_ATTRIBUTE

typedef int8_t q7_t;
typedef int16_t q15_t;
typedef int32_t q31_t;
typedef int64_t q63_t;

static inline int32_t nmsis_ssat(int64_t value, uint32_t bits)
{
    int64_t maximum = ((int64_t)1 << (bits - 1U)) - 1;
    int64_t minimum = -maximum - 1;
    if (value > maximum) return (int32_t)maximum;
    if (value < minimum) return (int32_t)minimum;
    return (int32_t)value;
}

#define __SSAT(value, bits) nmsis_ssat((int64_t)(value), (bits))
#define __QADD(a, b) nmsis_ssat((int64_t)(a) + (b), 32)
#define __QSUB(a, b) nmsis_ssat((int64_t)(a) - (b), 32)
#define __QADD16(a, b) nmsis_ssat((int32_t)(a) + (b), 16)
#define __QSUB16(a, b) nmsis_ssat((int32_t)(a) - (b), 16)

static inline q31_t clip_q63_to_q31(q63_t value)
{
    return (q31_t)nmsis_ssat(value, 32);
}

#endif
