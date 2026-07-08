#include <tool.h>
#include "tests.h"

int main(void)
{
    int failures = test_biquad_q31() + test_basic_math_integer();
    if (failures != 0) {
        printf("NMSIS DSP integer baseline: FAIL count=%d\n", failures);
        return 1;
    }
    printf("NMSIS DSP integer baseline: PASS\n");
    return 0;
}
