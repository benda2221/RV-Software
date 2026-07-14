#ifndef ZIRCON_NMSIS_VALIDATE_H
#define ZIRCON_NMSIS_VALIDATE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "riscv_math.h"

static uint32_t zircon_test_prng_state = 1U;

static inline void do_srand(void)
{
    zircon_test_prng_state = 1U;
}

static inline uint32_t zircon_test_rand(void)
{
    uint32_t value = zircon_test_prng_state;
    value ^= value << 13;
    value ^= value >> 17;
    value ^= value << 5;
    zircon_test_prng_state = value;
    return value;
}

#define srand(seed) do { zircon_test_prng_state = (uint32_t)(seed) ?: 1U; } while (0)
#define rand() ((int)(zircon_test_rand() & 0x7fffffffU))
#ifndef RAND_MAX
#define RAND_MAX 0x7fffffff
#endif
#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

static inline void generate_rand_q7(q7_t *src, int length)
{
    do_srand();
    for (int i = 0; i < length; i++) src[i] = (q7_t)zircon_test_rand();
}

static inline void generate_rand_q15(q15_t *src, int length)
{
    do_srand();
    for (int i = 0; i < length; i++) src[i] = (q15_t)zircon_test_rand();
}

static inline void generate_rand_q31(q31_t *src, int length)
{
    do_srand();
    for (int i = 0; i < length; i++) src[i] = (q31_t)zircon_test_rand();
}

static inline void generate_rand_f32(float32_t *src, int length)
{
    do_srand();
    for (int i = 0; i < length; i++)
        src[i] = (float32_t)(int32_t)zircon_test_rand() / 2147483648.0f;
}

static inline void generate_rand_f64(float64_t *src, int length)
{
    do_srand();
    for (int i = 0; i < length; i++)
        src[i] = (float64_t)(int32_t)zircon_test_rand() / 2147483648.0;
}

static inline void generate_posi_def_symme_f32(const riscv_matrix_instance_f32 *pSrc,
                                               riscv_matrix_instance_f32 *pUnitMat,
                                               riscv_matrix_instance_f32 *pDot,
                                               riscv_matrix_instance_f32 *pDst)
{
    riscv_mat_trans_f32(pSrc, pDst);
    riscv_mat_mult_f32(pDst, pSrc, pDot);
    riscv_mat_add_f32(pDot, pUnitMat, pDst);
}

#define TEST_ASSERT_TRUE(condition) do { \
    if (!(condition)) printf("ASSERT %s:%d: %s\n", __FILE__, __LINE__, #condition); \
} while (0)
#define TEST_ASSERT_EQUAL(expected, actual) do { \
    if ((expected) != (actual)) printf("ASSERT %s:%d\n", __FILE__, __LINE__); \
} while (0)

static inline int validate(int8_t *actual, const int8_t *reference, int size)
{
    int passed = true;
    for (int i = 0; i < size; i++) {
        if (actual[i] != reference[i]) {
            printf("FAIL index=%d actual=%d expected=%d\n", i, actual[i], reference[i]);
            passed = false;
        }
    }
    return passed;
}

#endif
