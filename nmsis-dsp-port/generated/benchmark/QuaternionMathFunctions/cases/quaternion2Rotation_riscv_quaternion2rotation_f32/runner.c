#include <stdio.h>
extern void quaternion2Rotation_riscv_quaternion2rotation_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions/quaternion2Rotation_riscv_quaternion2rotation_f32\n");
    printf("RUN quaternion2Rotation_riscv_quaternion2rotation_f32\n");
    quaternion2Rotation_riscv_quaternion2rotation_f32();
    printf("PASS benchmark/QuaternionMathFunctions/quaternion2Rotation_riscv_quaternion2rotation_f32 count=%d\n", 1);
    return 0;
}
