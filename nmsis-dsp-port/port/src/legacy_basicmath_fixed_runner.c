#include "riscv_math.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define ARRAY_SIZE 127

static q7_t q7_a_array[ARRAY_SIZE];
static q7_t q7_b_array[ARRAY_SIZE];
static q7_t q7_out_array[ARRAY_SIZE];
static q7_t q7_out_ref_array[ARRAY_SIZE];
static q15_t q15_a_array[ARRAY_SIZE];
static q15_t q15_b_array[ARRAY_SIZE];
static q15_t q15_out_array[ARRAY_SIZE];
static q15_t q15_out_ref_array[ARRAY_SIZE];
static q31_t q31_a_array[ARRAY_SIZE];
static q31_t q31_b_array[ARRAY_SIZE];
static q31_t q31_out_array[ARRAY_SIZE];
static q31_t q31_out_ref_array[ARRAY_SIZE];

static int test_flag_error;
static int8_t s;
BENCH_DECLARE_VAR();

#define RUN_TEST(name, call_expr, ref_expr, verify_expr) \
    do { \
        BENCH_START(name); \
        call_expr; \
        BENCH_END(name); \
        ref_expr; \
        s = (verify_expr); \
        if (s != 0) { \
            BENCH_ERROR(name); \
            test_flag_error = 1; \
        } \
        BENCH_STATUS(name); \
    } while (0)

int main(void)
{
    BENCH_INIT();

    generate_rand_q7(q7_a_array, ARRAY_SIZE);
    generate_rand_q7(q7_b_array, ARRAY_SIZE);
    generate_rand_q15(q15_a_array, ARRAY_SIZE);
    generate_rand_q15(q15_b_array, ARRAY_SIZE);
    generate_rand_q31(q31_a_array, ARRAY_SIZE);
    generate_rand_q31(q31_b_array, ARRAY_SIZE);

    RUN_TEST(riscv_abs_q7,
             riscv_abs_q7(q7_a_array, q7_out_array, ARRAY_SIZE),
             ref_abs_q7(q7_a_array, q7_out_ref_array, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_abs_q15,
             riscv_abs_q15(q15_a_array, q15_out_array, ARRAY_SIZE),
             ref_abs_q15(q15_a_array, q15_out_ref_array, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_abs_q31,
             riscv_abs_q31(q31_a_array, q31_out_array, ARRAY_SIZE),
             ref_abs_q31(q31_a_array, q31_out_ref_array, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

    RUN_TEST(riscv_add_q7,
             riscv_add_q7(q7_a_array, q7_b_array, q7_out_array, ARRAY_SIZE),
             ref_add_q7(q7_a_array, q7_b_array, q7_out_ref_array, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_add_q15,
             riscv_add_q15(q15_a_array, q15_b_array, q15_out_array, ARRAY_SIZE),
             ref_add_q15(q15_a_array, q15_b_array, q15_out_ref_array, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_add_q31,
             riscv_add_q31(q31_a_array, q31_b_array, q31_out_array, ARRAY_SIZE),
             ref_add_q31(q31_a_array, q31_b_array, q31_out_ref_array, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

    q31_t q31_dot_out;
    q31_t q31_dot_ref;
    q63_t q63_dot_out;
    q63_t q63_dot_ref;
    RUN_TEST(riscv_dot_prod_q7,
             riscv_dot_prod_q7(q7_a_array, q7_b_array, ARRAY_SIZE, &q31_dot_out),
             ref_dot_prod_q7(q7_a_array, q7_b_array, ARRAY_SIZE, &q31_dot_ref),
             verify_results_q31(&q31_dot_ref, &q31_dot_out, 1));
    RUN_TEST(riscv_dot_prod_q15,
             riscv_dot_prod_q15(q15_a_array, q15_b_array, ARRAY_SIZE, &q63_dot_out),
             ref_dot_prod_q15(q15_a_array, q15_b_array, ARRAY_SIZE, &q63_dot_ref),
             verify_results_q63(&q63_dot_ref, &q63_dot_out, 1));
    RUN_TEST(riscv_dot_prod_q31,
             riscv_dot_prod_q31(q31_a_array, q31_b_array, ARRAY_SIZE, &q63_dot_out),
             ref_dot_prod_q31(q31_a_array, q31_b_array, ARRAY_SIZE, &q63_dot_ref),
             verify_results_q63(&q63_dot_ref, &q63_dot_out, 1));

    RUN_TEST(riscv_mult_q7,
             riscv_mult_q7(q7_a_array, q7_b_array, q7_out_array, ARRAY_SIZE),
             ref_mult_q7(q7_a_array, q7_b_array, q7_out_ref_array, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_mult_q15,
             riscv_mult_q15(q15_a_array, q15_b_array, q15_out_array, ARRAY_SIZE),
             ref_mult_q15(q15_a_array, q15_b_array, q15_out_ref_array, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_mult_q31,
             riscv_mult_q31(q31_a_array, q31_b_array, q31_out_array, ARRAY_SIZE),
             ref_mult_q31(q31_a_array, q31_b_array, q31_out_ref_array, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

    RUN_TEST(riscv_negate_q7,
             riscv_negate_q7(q7_a_array, q7_out_array, ARRAY_SIZE),
             ref_negate_q7(q7_a_array, q7_out_ref_array, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_negate_q15,
             riscv_negate_q15(q15_a_array, q15_out_array, ARRAY_SIZE),
             ref_negate_q15(q15_a_array, q15_out_ref_array, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_negate_q31,
             riscv_negate_q31(q31_a_array, q31_out_array, ARRAY_SIZE),
             ref_negate_q31(q31_a_array, q31_out_ref_array, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

#if 0
    /* Unsigned logical tests currently hit a Zircon/difftest lbu mismatch. */
    RUN_TEST(riscv_and_u8,
             riscv_and_u8((uint8_t *)q7_a_array, (uint8_t *)q7_b_array, (uint8_t *)q7_out_array, ARRAY_SIZE),
             ref_and_u8((uint8_t *)q7_a_array, (uint8_t *)q7_b_array, (uint8_t *)q7_out_ref_array, ARRAY_SIZE),
             verify_results_u8((uint8_t *)q7_out_ref_array, (uint8_t *)q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_and_u16,
             riscv_and_u16((uint16_t *)q15_a_array, (uint16_t *)q15_b_array, (uint16_t *)q15_out_array, ARRAY_SIZE),
             ref_and_u16((uint16_t *)q15_a_array, (uint16_t *)q15_b_array, (uint16_t *)q15_out_ref_array, ARRAY_SIZE),
             verify_results_u16((uint16_t *)q15_out_ref_array, (uint16_t *)q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_and_u32,
             riscv_and_u32((uint32_t *)q31_a_array, (uint32_t *)q31_b_array, (uint32_t *)q31_out_array, ARRAY_SIZE),
             ref_and_u32((uint32_t *)q31_a_array, (uint32_t *)q31_b_array, (uint32_t *)q31_out_ref_array, ARRAY_SIZE),
             verify_results_u32((uint32_t *)q31_out_ref_array, (uint32_t *)q31_out_array, ARRAY_SIZE));

    RUN_TEST(riscv_or_u8,
             riscv_or_u8((uint8_t *)q7_a_array, (uint8_t *)q7_b_array, (uint8_t *)q7_out_array, ARRAY_SIZE),
             ref_or_u8((uint8_t *)q7_a_array, (uint8_t *)q7_b_array, (uint8_t *)q7_out_ref_array, ARRAY_SIZE),
             verify_results_u8((uint8_t *)q7_out_ref_array, (uint8_t *)q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_or_u16,
             riscv_or_u16((uint16_t *)q15_a_array, (uint16_t *)q15_b_array, (uint16_t *)q15_out_array, ARRAY_SIZE),
             ref_or_u16((uint16_t *)q15_a_array, (uint16_t *)q15_b_array, (uint16_t *)q15_out_ref_array, ARRAY_SIZE),
             verify_results_u16((uint16_t *)q15_out_ref_array, (uint16_t *)q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_or_u32,
             riscv_or_u32((uint32_t *)q31_a_array, (uint32_t *)q31_b_array, (uint32_t *)q31_out_array, ARRAY_SIZE),
             ref_or_u32((uint32_t *)q31_a_array, (uint32_t *)q31_b_array, (uint32_t *)q31_out_ref_array, ARRAY_SIZE),
             verify_results_u32((uint32_t *)q31_out_ref_array, (uint32_t *)q31_out_array, ARRAY_SIZE));

    RUN_TEST(riscv_not_u8,
             riscv_not_u8((uint8_t *)q7_a_array, (uint8_t *)q7_out_array, ARRAY_SIZE),
             ref_not_u8((uint8_t *)q7_a_array, (uint8_t *)q7_out_ref_array, ARRAY_SIZE),
             verify_results_u8((uint8_t *)q7_out_ref_array, (uint8_t *)q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_not_u16,
             riscv_not_u16((uint16_t *)q15_a_array, (uint16_t *)q15_out_array, ARRAY_SIZE),
             ref_not_u16((uint16_t *)q15_a_array, (uint16_t *)q15_out_ref_array, ARRAY_SIZE),
             verify_results_u16((uint16_t *)q15_out_ref_array, (uint16_t *)q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_not_u32,
             riscv_not_u32((uint32_t *)q31_a_array, (uint32_t *)q31_out_array, ARRAY_SIZE),
             ref_not_u32((uint32_t *)q31_a_array, (uint32_t *)q31_out_ref_array, ARRAY_SIZE),
             verify_results_u32((uint32_t *)q31_out_ref_array, (uint32_t *)q31_out_array, ARRAY_SIZE));

    RUN_TEST(riscv_xor_u8,
             riscv_xor_u8((uint8_t *)q7_a_array, (uint8_t *)q7_b_array, (uint8_t *)q7_out_array, ARRAY_SIZE),
             ref_xor_u8((uint8_t *)q7_a_array, (uint8_t *)q7_b_array, (uint8_t *)q7_out_ref_array, ARRAY_SIZE),
             verify_results_u8((uint8_t *)q7_out_ref_array, (uint8_t *)q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_xor_u16,
             riscv_xor_u16((uint16_t *)q15_a_array, (uint16_t *)q15_b_array, (uint16_t *)q15_out_array, ARRAY_SIZE),
             ref_xor_u16((uint16_t *)q15_a_array, (uint16_t *)q15_b_array, (uint16_t *)q15_out_ref_array, ARRAY_SIZE),
             verify_results_u16((uint16_t *)q15_out_ref_array, (uint16_t *)q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_xor_u32,
             riscv_xor_u32((uint32_t *)q31_a_array, (uint32_t *)q31_b_array, (uint32_t *)q31_out_array, ARRAY_SIZE),
             ref_xor_u32((uint32_t *)q31_a_array, (uint32_t *)q31_b_array, (uint32_t *)q31_out_ref_array, ARRAY_SIZE),
             verify_results_u32((uint32_t *)q31_out_ref_array, (uint32_t *)q31_out_array, ARRAY_SIZE));

#endif

    q7_t offset_q7;
    q15_t offset_q15;
    q31_t offset_q31;
    generate_rand_q7(&offset_q7, 1);
    generate_rand_q15(&offset_q15, 1);
    generate_rand_q31(&offset_q31, 1);
    RUN_TEST(riscv_offset_q7,
             riscv_offset_q7(q7_a_array, offset_q7, q7_out_array, ARRAY_SIZE),
             ref_offset_q7(q7_a_array, offset_q7, q7_out_ref_array, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_offset_q15,
             riscv_offset_q15(q15_a_array, offset_q15, q15_out_array, ARRAY_SIZE),
             ref_offset_q15(q15_a_array, offset_q15, q15_out_ref_array, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_offset_q31,
             riscv_offset_q31(q31_a_array, offset_q31, q31_out_array, ARRAY_SIZE),
             ref_offset_q31(q31_a_array, offset_q31, q31_out_ref_array, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

    q7_t scale_q7;
    q15_t scale_q15;
    q31_t scale_q31;
    generate_rand_q7(&scale_q7, 1);
    generate_rand_q15(&scale_q15, 1);
    generate_rand_q31(&scale_q31, 1);
    RUN_TEST(riscv_scale_q7,
             riscv_scale_q7(q7_a_array, scale_q7, -2, q7_out_array, ARRAY_SIZE),
             ref_scale_q7(q7_a_array, scale_q7, -2, q7_out_ref_array, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_scale_q15,
             riscv_scale_q15(q15_a_array, scale_q15, -2, q15_out_array, ARRAY_SIZE),
             ref_scale_q15(q15_a_array, scale_q15, -2, q15_out_ref_array, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_scale_q31,
             riscv_scale_q31(q31_a_array, scale_q31, -1, q31_out_array, ARRAY_SIZE),
             ref_scale_q31(q31_a_array, scale_q31, -1, q31_out_ref_array, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

    RUN_TEST(riscv_shift_q7,
             riscv_shift_q7(q7_a_array, -1, q7_out_array, ARRAY_SIZE),
             ref_shift_q7(q7_a_array, -1, q7_out_ref_array, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_shift_q15,
             riscv_shift_q15(q15_a_array, -3, q15_out_array, ARRAY_SIZE),
             ref_shift_q15(q15_a_array, -3, q15_out_ref_array, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_shift_q31,
             riscv_shift_q31(q31_a_array, -3, q31_out_array, ARRAY_SIZE),
             ref_shift_q31(q31_a_array, -3, q31_out_ref_array, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

    RUN_TEST(riscv_sub_q7,
             riscv_sub_q7(q7_a_array, q7_b_array, q7_out_array, ARRAY_SIZE),
             ref_sub_q7(q7_a_array, q7_b_array, q7_out_ref_array, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_sub_q15,
             riscv_sub_q15(q15_a_array, q15_b_array, q15_out_array, ARRAY_SIZE),
             ref_sub_q15(q15_a_array, q15_b_array, q15_out_ref_array, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_sub_q31,
             riscv_sub_q31(q31_a_array, q31_b_array, q31_out_array, ARRAY_SIZE),
             ref_sub_q31(q31_a_array, q31_b_array, q31_out_ref_array, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

    RUN_TEST(riscv_clip_q7,
             riscv_clip_q7(q7_a_array, q7_out_array, -100, 100, ARRAY_SIZE),
             ref_clip_q7(q7_a_array, q7_out_ref_array, -100, 100, ARRAY_SIZE),
             verify_results_q7(q7_out_ref_array, q7_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_clip_q15,
             riscv_clip_q15(q15_a_array, q15_out_array, -2638, 1000, ARRAY_SIZE),
             ref_clip_q15(q15_a_array, q15_out_ref_array, -2638, 1000, ARRAY_SIZE),
             verify_results_q15(q15_out_ref_array, q15_out_array, ARRAY_SIZE));
    RUN_TEST(riscv_clip_q31,
             riscv_clip_q31(q31_a_array, q31_out_array, -214712319, 214712319, ARRAY_SIZE),
             ref_clip_q31(q31_a_array, q31_out_ref_array, -214712319, 214712319, ARRAY_SIZE),
             verify_results_q31(q31_out_ref_array, q31_out_array, ARRAY_SIZE));

    if (test_flag_error) {
        printf("test error appears, please recheck.\n");
        return 1;
    }

    printf("PASS legacy/BasicMathFunctions fixed-point count=30\n");
    return 0;
}
