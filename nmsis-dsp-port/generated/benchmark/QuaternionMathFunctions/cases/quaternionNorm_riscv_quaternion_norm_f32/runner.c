#include <stdio.h>
extern void quaternionNorm_riscv_quaternion_norm_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions/quaternionNorm_riscv_quaternion_norm_f32\n");
    printf("RUN quaternionNorm_riscv_quaternion_norm_f32\n");
    quaternionNorm_riscv_quaternion_norm_f32();
    printf("PASS benchmark/QuaternionMathFunctions/quaternionNorm_riscv_quaternion_norm_f32 count=%d\n", 1);
    return 0;
}
