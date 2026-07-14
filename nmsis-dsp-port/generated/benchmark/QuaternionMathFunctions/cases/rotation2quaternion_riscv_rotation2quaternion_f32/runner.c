#include <stdio.h>
extern void rotation2quaternion_riscv_rotation2quaternion_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions/rotation2quaternion_riscv_rotation2quaternion_f32\n");
    printf("RUN rotation2quaternion_riscv_rotation2quaternion_f32\n");
    rotation2quaternion_riscv_rotation2quaternion_f32();
    printf("PASS benchmark/QuaternionMathFunctions/rotation2quaternion_riscv_rotation2quaternion_f32 count=%d\n", 1);
    return 0;
}
