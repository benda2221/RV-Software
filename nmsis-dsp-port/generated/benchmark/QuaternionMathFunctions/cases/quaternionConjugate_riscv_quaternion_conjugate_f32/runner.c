#include <stdio.h>
extern void quaternionConjugate_riscv_quaternion_conjugate_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions/quaternionConjugate_riscv_quaternion_conjugate_f32\n");
    printf("RUN quaternionConjugate_riscv_quaternion_conjugate_f32\n");
    quaternionConjugate_riscv_quaternion_conjugate_f32();
    printf("PASS benchmark/QuaternionMathFunctions/quaternionConjugate_riscv_quaternion_conjugate_f32 count=%d\n", 1);
    return 0;
}
