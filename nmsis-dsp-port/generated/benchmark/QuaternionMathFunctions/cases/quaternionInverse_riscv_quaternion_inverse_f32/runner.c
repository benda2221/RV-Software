#include <stdio.h>
extern void quaternionInverse_riscv_quaternion_inverse_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions/quaternionInverse_riscv_quaternion_inverse_f32\n");
    printf("RUN quaternionInverse_riscv_quaternion_inverse_f32\n");
    quaternionInverse_riscv_quaternion_inverse_f32();
    printf("PASS benchmark/QuaternionMathFunctions/quaternionInverse_riscv_quaternion_inverse_f32 count=%d\n", 1);
    return 0;
}
