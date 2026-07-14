#include <stdio.h>
extern void quaternionNormalize_riscv_quaternion_normalize_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions/quaternionNormalize_riscv_quaternion_normalize_f32\n");
    printf("RUN quaternionNormalize_riscv_quaternion_normalize_f32\n");
    quaternionNormalize_riscv_quaternion_normalize_f32();
    printf("PASS benchmark/QuaternionMathFunctions/quaternionNormalize_riscv_quaternion_normalize_f32 count=%d\n", 1);
    return 0;
}
