#include <stdio.h>
extern void quaternion2Rotation_riscv_quaternion2rotation_f32(void);
extern void quaternionConjugate_riscv_quaternion_conjugate_f32(void);
extern void quaternionInverse_riscv_quaternion_inverse_f32(void);
extern void quaternionNorm_riscv_quaternion_norm_f32(void);
extern void quaternionNormalize_riscv_quaternion_normalize_f32(void);
extern void quaternionProduct_riscv_quaternion_product_f32(void);
extern void quaternionProductSingle_riscv_quaternion_product_single_f32(void);
extern void rotation2quaternion_riscv_rotation2quaternion_f32(void);

int main(void)
{
    printf("Start benchmark/QuaternionMathFunctions\n");
    printf("RUN quaternion2Rotation_riscv_quaternion2rotation_f32\n");
    quaternion2Rotation_riscv_quaternion2rotation_f32();
    printf("RUN quaternionConjugate_riscv_quaternion_conjugate_f32\n");
    quaternionConjugate_riscv_quaternion_conjugate_f32();
    printf("RUN quaternionInverse_riscv_quaternion_inverse_f32\n");
    quaternionInverse_riscv_quaternion_inverse_f32();
    printf("RUN quaternionNorm_riscv_quaternion_norm_f32\n");
    quaternionNorm_riscv_quaternion_norm_f32();
    printf("RUN quaternionNormalize_riscv_quaternion_normalize_f32\n");
    quaternionNormalize_riscv_quaternion_normalize_f32();
    printf("RUN quaternionProduct_riscv_quaternion_product_f32\n");
    quaternionProduct_riscv_quaternion_product_f32();
    printf("RUN quaternionProductSingle_riscv_quaternion_product_single_f32\n");
    quaternionProductSingle_riscv_quaternion_product_single_f32();
    printf("RUN rotation2quaternion_riscv_rotation2quaternion_f32\n");
    rotation2quaternion_riscv_rotation2quaternion_f32();
    printf("PASS benchmark/QuaternionMathFunctions count=%d\n", 8);
    return 0;
}
