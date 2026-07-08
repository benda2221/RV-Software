#include <stdint.h>
#include <tool.h>
#include "dsp/basic_math_functions.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
static int check_value(const char *name, unsigned int index,
                       int32_t expected, int32_t actual)
{
    if (expected == actual) return 0;
    printf("FAIL %s index=%u expected=%d actual=%d\n", name, index, expected, actual);
    return 1;
}

#define DEFINE_INTEGER_TESTS(suffix, type, bits, minimum, maximum) \
static int test_##suffix(void) { \
    static const type a[] = {minimum, -100, -1, 0, 1, 100, maximum}; \
    static const type b[] = {-1, minimum, 2, maximum, -2, maximum, 1}; \
    type out[ARRAY_SIZE(a)]; int failures = 0; unsigned int i; \
    riscv_abs_##suffix(a, out, ARRAY_SIZE(a)); \
    for (i = 0; i < ARRAY_SIZE(a); i++) { int64_t v = a[i]; \
        int32_t e = v == minimum ? maximum : (v < 0 ? (int32_t)-v : (int32_t)v); \
        failures += check_value("abs_" #suffix, i, e, out[i]); } \
    riscv_negate_##suffix(a, out, ARRAY_SIZE(a)); \
    for (i = 0; i < ARRAY_SIZE(a); i++) { \
        int32_t e = a[i] == minimum ? maximum : -(int32_t)a[i]; \
        failures += check_value("negate_" #suffix, i, e, out[i]); } \
    riscv_add_##suffix(a, b, out, ARRAY_SIZE(a)); \
    for (i = 0; i < ARRAY_SIZE(a); i++) \
        failures += check_value("add_" #suffix, i, nmsis_ssat((int64_t)a[i] + b[i], bits), out[i]); \
    riscv_sub_##suffix(a, b, out, ARRAY_SIZE(a)); \
    for (i = 0; i < ARRAY_SIZE(a); i++) \
        failures += check_value("sub_" #suffix, i, nmsis_ssat((int64_t)a[i] - b[i], bits), out[i]); \
    return failures; }

DEFINE_INTEGER_TESTS(q7, q7_t, 8, INT8_MIN, INT8_MAX)
DEFINE_INTEGER_TESTS(q15, q15_t, 16, INT16_MIN, INT16_MAX)
DEFINE_INTEGER_TESTS(q31, q31_t, 32, INT32_MIN, INT32_MAX)

int test_basic_math_integer(void)
{
    int failures = test_q7() + test_q15() + test_q31();
    printf("%s basic_math_integer\n", failures == 0 ? "PASS" : "FAIL");
    return failures;
}
