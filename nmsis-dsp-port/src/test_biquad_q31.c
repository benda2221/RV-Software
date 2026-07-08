#include <tool.h>
#include "dsp/filtering_functions.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
static const q31_t coefficients[] = {
    1073741824, 0, 0, 0, 0, 1073741824, 0, 0, 0, 0,
};
static const q31_t input[] = {
    0, 134217728, -134217728, 268435456, -268435456, 536870912,
    -536870912, 67108864, 33554432, -33554432, 16777216, -16777216,
};
static q31_t state[8];
static q31_t output[ARRAY_SIZE(input)];

int test_biquad_q31(void)
{
    riscv_biquad_casd_df1_inst_q31 filter;
    int failures = 0;
    riscv_biquad_cascade_df1_init_q31(&filter, 2, coefficients, state, 1);
    riscv_biquad_cascade_df1_q31(&filter, input, output, ARRAY_SIZE(input));
    for (unsigned int i = 0; i < ARRAY_SIZE(input); i++) {
        if (output[i] != input[i]) {
            printf("FAIL biquad_q31 index=%u expected=%d actual=%d\n",
                   i, input[i], output[i]);
            failures++;
        }
    }
    printf("%s biquad_q31\n", failures == 0 ? "PASS" : "FAIL");
    return failures;
}
