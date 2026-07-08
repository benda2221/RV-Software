#ifndef ZIRCON_NMSIS_CORE_H
#define ZIRCON_NMSIS_CORE_H

#include <stdint.h>
#include <string.h>

#define __RISCV_XLEN 32
#define __STATIC_INLINE static inline
#define __STATIC_FORCEINLINE static inline __attribute__((always_inline))
#define __ALIGNED(x) __attribute__((aligned(x)))
#define __WEAK __attribute__((weak))

__STATIC_FORCEINLINE uint32_t __CLZ(uint32_t value)
{
    return value == 0U ? 32U : (uint32_t)__builtin_clz(value);
}

__STATIC_FORCEINLINE int32_t __SSAT(int64_t value, uint32_t bits)
{
    int64_t maximum = ((int64_t)1 << (bits - 1U)) - 1;
    int64_t minimum = -maximum - 1;
    if (value > maximum) return (int32_t)maximum;
    if (value < minimum) return (int32_t)minimum;
    return (int32_t)value;
}

__STATIC_FORCEINLINE uint32_t __USAT(int64_t value, uint32_t bits)
{
    uint64_t maximum = bits == 32U ? UINT32_MAX : (((uint64_t)1 << bits) - 1U);
    if (value < 0) return 0U;
    if ((uint64_t)value > maximum) return (uint32_t)maximum;
    return (uint32_t)value;
}

__STATIC_FORCEINLINE uint32_t __ROR(uint32_t value, uint32_t shift)
{
    shift &= 31U;
    return shift == 0U ? value : (value >> shift) | (value << (32U - shift));
}

#define __LD(address) (*(const int64_t *)(address))
#define __SD(address, value) (*(int64_t *)(address) = (int64_t)(value))
#define __LW(address) (*(const int32_t *)(address))
#define __SW(address, value) (*(int32_t *)(address) = (int32_t)(value))
#define __QADD(a, b) __SSAT((int64_t)(a) + (b), 32)
#define __QSUB(a, b) __SSAT((int64_t)(a) - (b), 32)
#define __QADD16(a, b) __SSAT((int32_t)(a) + (b), 16)
#define __QSUB16(a, b) __SSAT((int32_t)(a) - (b), 16)
#define __PKHBT(a, b, shift) (((uint32_t)(a) & 0xffffU) | ((uint32_t)(b) << (shift)))
#define __PKHTB(a, b, shift) (((uint32_t)(a) & 0xffff0000U) | (((uint32_t)(b) >> (shift)) & 0xffffU))

#endif
